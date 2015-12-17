#include "ccell.h"

CCell::CCell(string s) : m_expression(s) {

}

const string CCell::GetExpression() const {
	return m_expression;
}

const string CCell::Type() const {
	return m_type;
}

CCell::~CCell() {

}
