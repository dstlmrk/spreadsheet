#include "ctable.h"

CTable::CTable() {}

const string CTable::GetExpression(const char cell_x, const int cell_y) {
	if (Find(cell_x,cell_y)) {
		return m_Data[cell_x][cell_y]->GetExpression();
	}
	return "";
}

const string CTable::GetOutput(const char cell_x, const int cell_y) {
	if (Find(cell_x,cell_y)) {
			if (Type(cell_x,cell_y)=="STRING") {
				return m_Data[cell_x][cell_y]->GetOutput();
			} else {
				int pointer = 0;
				double val = 0;
				string s = m_Data[cell_x][cell_y]->GetOutput();
				if ( Expr( false, s, pointer, &val, LEX_NULL, cell_x, cell_y) ) {
					return DoubleToString(val);
				} else {
					return "ERROR";
				}
			}
	}
	return "";
}

bool CTable::NewCell(const string & s,const char cell_x,const int cell_y) {

	string expression = s;
	string edited_expression = s;

	int result = Parse(edited_expression, cell_x, cell_y);

	if (result==0) {
		return false;
	} else if (result==1) {
		if (Find(cell_x, cell_y)) {
			Delete(cell_x, cell_y);
		}
		CStringCell * ptr = new CStringCell(expression, edited_expression);
		m_Data[cell_x][cell_y]=ptr;
	} else if (result==2) {
		if (Find(cell_x, cell_y)) {
			Delete(cell_x, cell_y);
		}
		CIntCell * ptr = new CIntCell(expression);
		m_Data[cell_x][cell_y]=ptr;
	}

	return true;
}

bool CTable::Find(const char cell_x, const int cell_y) {
	if (m_Data.find(cell_x) != m_Data.end()) {
		if (m_Data[cell_x].find(cell_y) != m_Data[cell_x].end()) {
			return true;
		}
	}
	return false;
}

void CTable::Delete(const char cell_x, const int cell_y) {
	// delete all links with this cell
	DelLinks(cell_x, cell_y);
	map<int, const CCell*>::iterator it;
	it = m_Data[cell_x].find(cell_y);
	delete it->second;
}

const string CTable::Type(const char cell_x,const int cell_y) {
	if (Find(cell_x,cell_y)) {
			return m_Data[cell_x][cell_y]->Type();
	}
	return "";
}

const int CTable::Parse(string & s, const char cell_x, const int cell_y) {
	int string_begin=-1;
	int string_end=105;

	// looking for first and last delimiter means string
	for (int i=0; i<(int)s.size(); i++) {
		if (s[i]==' ') {
			continue;
		} else if (s[i]=='\"') {
			string_begin = i;
			break;
		}
	}

	for (int i=(int)s.size()-1; i>=0; i--) {
		if (s[i]==' ') {
			continue;
		} else if (s[i]=='\"') {
			string_end = i;
			break;
		}
	}

	// erase string before first delimiter and behind last delimiter
	if (string_begin>-1 && string_end<105 && string_begin!=string_end) {
		s.erase(s.begin(), s.begin()+string_begin+1);
		s.erase(s.begin()+string_end-1, s.end());
		return 1;
	}

	// check, if input string is number type
	int pointer = 0;
	double val;
	if ( Expr(true, s, pointer, &val, LEX_NULL, cell_x, cell_y) ) {
		return 2;
	}

	return 0;
}

bool CTable::AddLink(char cell_x, int cell_y, char _cell_x, int _cell_y) {

	pair<char, int> print_cell;
	pair<char, int> data_cell;

	print_cell.first = cell_x;
	print_cell.second = cell_y;

	data_cell.first = _cell_x;
	data_cell.second = _cell_y;

	m_links.insert(pair< pair<char,int>, pair<char,int> >(print_cell, data_cell));

	return true;
}

void CTable::DelLinks(char cell_x, int cell_y) {
	pair<char, int> tmp;
	tmp.first = cell_x;
	tmp.second = cell_y;
	m_links.erase (tmp);
}

bool CTable::CheckLinks(char cell_x, int cell_y, char _cell_x, int _cell_y) {

	multimap< pair<char,int>, pair<char,int> >::iterator it;

	for (it=m_links.begin(); it!=m_links.end(); it++) {
		if (it->first.first==_cell_x && it->first.second==_cell_y) {
			if (it->second.first==cell_x && it->second.second==cell_y) {
				return false;
			} else {
				if (!CheckLinks( cell_x, cell_y, it->second.first, it->second.second)) {
					return false;
				}
			}
		}
	}

	return true;
}

const char * CTable::StringToCharArray(const string & s) {
	const char * cstr = s.c_str();
	return cstr;
}

const string CTable::DoubleToString(const double & d) {
	stringstream ss;
	string s;
	ss << d;
	ss >> s;
	return s;
}

int CTable::NextToken ( bool init, string str, int & i, double * val, char cell_x, int cell_y) {
	
	char c;
	while (isspace(str[i])) {
		i++;
	}

	if ( (int)str.size() <= i ) return ( LEX_NULL );

	c = str[i];
	i++;

	if ( c == '+' ) return ( LEX_ADD );
	if ( c == '-' ) return ( LEX_SUB );
	if ( c == '*' ) return ( LEX_MUL );
	if ( c == '/' ) return ( LEX_DIV );
	if ( c == '(' ) return ( LEX_LPA );
	if ( c == ')' ) return ( LEX_RPA );

	char _cell_x;
	int _cell_y = 0;


	// error or coordinate
	if ( ! isdigit ( c ) ) {
		if (c>='A' && c<='Z') {

			_cell_x = c;
			c = str[i];
			i++;

			if ( isdigit ( c ) ) {

				// read row in coordinate
				while ( isdigit ( c ) ) {
					_cell_y = _cell_y * 10 + c - '0';
					c = str[i];
					i++;
				}
				i--;

				// if it is first process, it checks deadlock
				if (init==true) {
					init = false;
					if ((Type(_cell_x, _cell_y)=="STRING") || (_cell_x==cell_x && _cell_y==cell_y)) {
						return ( LEX_ERR );
					} else if (!Find( _cell_x, _cell_y)) {
						NewCell( "0", _cell_x, _cell_y);
						AddLink( cell_x, cell_y, _cell_x, _cell_y);
					} else {
						if (CheckLinks( cell_x, cell_y, _cell_x, _cell_y)) {
							AddLink( cell_x, cell_y, _cell_x, _cell_y);
						} else {
							return ( LEX_ERR );
						}
					}
				}

				string s = GetExpression(_cell_x, _cell_y);
					
					// from cell I want to get value
				int pointer = 0;
				double val_tmp = 0;
				if ( Expr(init, s, pointer, &val_tmp, LEX_NULL, cell_x, cell_y) ) {
						*val = val_tmp;
					return ( LEX_INT );
				}
			} else {
				return ( LEX_ERR );
			}
		}
		return ( LEX_ERR );
	}

	*val = 0;
	while ( isdigit ( c ) ) {
		*val = *val * 10 + c - '0';
		c = str[i];
		i++;
	}
	i--;

	return ( LEX_INT );
}

int CTable::Factor ( bool init, string str, int & i, double * val, char cell_x, int cell_y ) {
	int tok;

	tok = NextToken ( init, str, i, val, cell_x, cell_y );
	if ( tok == LEX_INT ) return ( 1 );
	if ( tok != LEX_LPA ) return ( 0 );
	return ( Expr ( init, str, i, val, LEX_RPA, cell_x, cell_y ) );
 }

int CTable::Expr ( bool init, string str, int & i, double * res, int whenToReturn, char cell_x, int cell_y ) {
	double x, dummy, mul;
	int token;

	// expression has form: number operator number operator...
	// first number is read out of cycle
	// to result it saves only terms, where will not any changes

	*res = 0;
	if ( ! Factor ( init, str, i, &mul, cell_x, cell_y ) ) {
		return ( 0 );
	}

	while ( 1 ) {
		token = NextToken ( init, str, i, &dummy, cell_x, cell_y );

		if ( token == whenToReturn ) {
			*res += mul;
			return ( 1 );
		}

		if ( ! Factor ( init, str, i, &x, cell_x, cell_y ) ) return ( 0 );

		switch ( token ) {
			case LEX_ADD:
				*res += mul;
				mul = x;
				break;
			case LEX_SUB:
			// here += mul, operator - is jointed with next term
				*res += mul;
				mul = -x;
				break;
			case LEX_MUL:
				mul *= x;
				break;
			case LEX_DIV:
				mul /= x;
				break;
			default:
				return ( 0 );
		}
	}
}

CTable::~CTable() {

	map<char, map<int, const CCell*> >::iterator it1;
	map<int, const CCell*>::iterator it2;
	for ( it1 = m_Data.begin(); it1 != m_Data.end(); it1++) {
		for ( it2 = it1->second.begin(); it2 != it1->second.end(); it2++) {
			delete it2->second;
		}
	}
}
