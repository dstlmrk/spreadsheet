#include "cintcell.h"

CIntCell::CIntCell(string s) : CCell(s) {
	m_type = "NUMBER";
}

// CIntCell * CIntCell::Clone() const {
// 	return new CIntCell (*this); 
// }

const string CIntCell::GetOutput() const {
	string output = m_expression;
	return output;
}
