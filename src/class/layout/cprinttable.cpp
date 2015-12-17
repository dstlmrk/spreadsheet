#include "cprinttable.h"

CPrintTable::CPrintTable() {
	m_DataTable = new CTable();
}

void CPrintTable::Table(const char table_x, const int table_y, const char cell_x, const int cell_y) const {
	
	CWindow::ClearWindow(0);

	mvaddstr (3, 2, " ACTUAL POSITION:");
	mvhline(2, 2, ACS_HLINE, 119);
	mvaddstr (1, 2, " EXPRESSION:");
	
	// coordinates of actual position of cursor
	mvaddstr (3, 20, CharToCharArray(cell_x));
	mvaddstr (3, 21, IntToCharArray(cell_y));

	// get the exact expression in one cell
	mvaddstr(1, 15, StringToCharArray(m_DataTable->GetExpression(cell_x, cell_y)));

	mvhline(4, 2, ACS_HLINE, 119);
	mvhline(6, 2, '=', 119);

	// print upper line with names of columns
	int j=19, cnt=0;
	for (char c=table_x; cnt<9; c++, cnt++) {
		mvaddstr(5, j, CharToCharArray(c));
		j=j+12;
	}

	// print left side with names of rows
	for (int i=table_y, cnt=0, j=7; cnt<10; i++, cnt++) {
		mvaddstr(j, 7, IntToCharArray(i) );
		j+=2;
	}

	// print horizontal lines
	for (int i=8; i<25;) {
		mvhline(i, 2, ACS_HLINE, 119);
		i+=2;
	}

	// print vertical lines
	for (int i=13; i<110;) {
		mvvline(5, i, ACS_VLINE, 21);
		i+=12;
	}

	CWindow::FooterForInput();

	// print outputs from each cells to table
	for (int i=0; i<10; i++) {
		for (int j=0; j<9; j++) {
			string output = m_DataTable->GetOutput(table_x+j, table_y+i);
			if (output.size()>11) {
				output = output.substr(0,11);
			}
			mvaddstr(7+i*2, 14+j*12, StringToCharArray(output));
		}
	}
}

void CPrintTable::NewInput(const char cell_x, const int cell_y) {

	CWindow::ClearFooter();
	init_pair (COLOR3, COLOR_RED,  COLOR_BLACK);
	mvhline(1, 15, ' ', 106);
	CWindow::FooterForSave();
	CWindow::SetCursor(1,15);

	string input;
	int c;

	bool error=false;

	while (c=getch()) {

		if (c=='\n' && (int)input.size()==0) {
			// empty input
			break;
		} else if (c=='\n') {
			// save process
			if (!m_DataTable->NewCell(input, cell_x, cell_y)) {
				// fail
				attron (COLOR_PAIR(COLOR3)); 
				mvaddstr (1, 14, " ERROR: again please");
				attroff(COLOR_PAIR(COLOR3));
				input = "";
				error = true;
			} else {
				// done
				CWindow::PrintFooter();
				mvhline(1, 15, ' ', 106);
				CWindow::SetCursorToStart();
				break;
			}
		// erase last char from input
		} else if (c==KEY_BACKSPACE && input.size()>0) {
			mvhline(1, 15, ' ', 106);
			input.erase(input.end()-1);
		// control, if input char is typical char
		} else if (IntToChar(c)>31 && IntToChar(c)<127 && input.size()<105) {
			if (error==true) {
				mvhline(1, 15, ' ', 106);
			}
			input = input + IntToChar(c);
		}

		// while every cycle print actual input
		mvaddstr (1, 15, StringToCharArray(input));

	}
}

const char CPrintTable::IntToChar(const int & i) const {
	char c = i;
	return c;
}

const char * CPrintTable::StringToCharArray(const string & s) const {
	const char * cstr = s.c_str();
	return cstr;
}

const char * CPrintTable::IntToCharArray(const int & i) const {
	stringstream ss;
	string s;
	ss << i;
	ss >> s;
	const char * cstr = s.c_str();
	return cstr;
}

const char * CPrintTable::CharToCharArray(const char & c) const {
	stringstream ss;
	string s;
	ss << c;
	ss >> s;
	const char * cstr = s.c_str();
	return cstr;
}

CPrintTable::~CPrintTable() {
	delete m_DataTable;
}
