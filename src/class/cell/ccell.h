#ifndef CCELL_H
#define CCELL_H

#include <cstring>
#include <sstream>

/*!
 * \class CCell
 * \brief Abstract class - parent of all cells.
 *
 * \fn CCell::CCell
 * \brief Creates new cell and saves him expression.
 * \param s [in] expression to save
 *
 * \fn CCell::~CCell
 * \brief Empty destructor.
 *
 * \fn CCell::GetExpression
 * \brief Get m_expression from cell.
 *
 * \fn CCell::GetOutput
 * \brief Get output from cell.
 *
 * \fn CCell::Type
 * \brief Get type of cell.
 */

using namespace std;

class CCell {
public:
	                     CCell               (string s);
	virtual              ~CCell              (void);
	const                stringGetExpression (void) const;
	virtual const string GetOutput           (void) const = 0;
	const                stringType          (void) const;
//virtual CCell * Clone	(void) const = 0;
protected:
    string m_expression;
    string m_type;
};

#endif /* CCELL_H */
