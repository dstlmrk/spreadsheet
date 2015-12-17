#include "cstringcell.h"

CStringCell::CStringCell(string in, string out) : CCell(in) {
	m_type = "STRING";
	m_output = out;
}

// CStringCell * CStringCell::Clone() const {
// 	return new CStringCell (*this); 
// }

const string CStringCell::GetOutput() const {
	return m_output;
}
