#ifndef CINTCELL_H
#define CINTCELL_H

#include "./ccell.h"

/*!
 * \class CIntCell
 * \brief Class represents number type of the cell.
 *
 * \fn CIntCell::CIntCell
 * \brief Creates new cell and saves him expression.
 * \param s [in] expression to save
 *
 * \fn CIntCell::GetOutput
 * \brief Get output from cell.
 *
 */

class CIntCell : public CCell {
public:
	CIntCell(string s);
	//CIntCell * Clone() const;
	const string GetOutput() const;
protected:
};

#endif /* CINTCELL_H */
