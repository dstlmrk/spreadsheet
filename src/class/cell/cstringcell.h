#ifndef CSTRINGCELL_H
#define CSTRINGCELL_H

#include "./ccell.h"

/*!
 * \class CStringCell
 * \brief Class represents string type of the cell.
 *
 * \fn CStringCell::CStringCell
 * \brief Creates new cell and saves him expression and string for output.
 * \param s [in] expression to save
 * \param s [in] expression to save
 *
 * \fn CStringCell::GetOutput
 * \brief Get output from cell.
 *
 */

class CStringCell : public CCell {
public:
	CStringCell(string, string);
	//CStringCell * Clone() const;
	const string GetOutput() const;
protected:
	string m_output;
};

#endif /* CSTRINGCELL_H */
