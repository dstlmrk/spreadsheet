#ifndef CPRINTTABLE_H
#define CPRINTTABLE_H

#include <ncurses.h>
#include <sstream>
#include <cstring>

#include "./cwindow.h"
#include "../table/ctable.h"
#include "./chelp.h"

using namespace std;

/*!
 * \class CPrintTable
 * \brief Print the table and all data from it.
 *
 * \fn CPrintTable::CPrintTable
 * \brief Create new instance of CTable, where are all saved data.
 *
 * \fn CPrintTable::~CPrintTable
 * \brief Destructor.
 *
 * \fn CPrintTable::Table
 * \param table_x [in] index of column, where is left upper corner for actual position
 * \param table_y [in] index of row, where is left upper corner for actual position
 * \param cell_x [in] index of column, where is actual position of cursor
 * \param cell_y [in] index of row, where is actual position of cursor
 * \brief This method prints the entire table and all data stored in it.
 *
 * \fn CPrintTable::NewInput
 * Checks correct inputs to cell and if it is good then save it.
 * \param cell_x [in] coordinates (column)
 * \param cell_y [in] coordinates (row)
 * \brief Process and checks the input and then save it.
 *
 * \fn CPrintTable::IntToChar
 * \param i [in] integer for convert
 * @return char
 * \brief Converts integer to char.
 *
 * \fn CPrintTable::StringToCharArray
 * \param s [in] string for convert
 * @return const char array
 * \brief Converts integer to char
 *
 * \fn CPrintTable::IntToCharArray
 * \param i [in] integer for convert
 * @return const char array
 * \brief Converts integer to char
 *
 * \fn CPrintTable::CharToCharArray
 * \param c [in] char for convert
 * @return const char array
 * \brief Converts integer to char
 */

class CPrintTable {
	
public:
	     CPrintTable  (void);
	     ~CPrintTable (void);
	void Table        (const char table_x, const int table_y, const char cell_x, const int cell_y) const;
	void NewInput     (const char cell_x, const int cell_y);

private:
	const char   IntToChar         (const int & i) const;
	const char * StringToCharArray (const string & s) const;
	const char * IntToCharArray    (const int & i) const;
	const char * CharToCharArray   (const char & c) const;

	//! Instance of CTable, where are all saved data.
	CTable * m_DataTable;

};

#endif /* CPRINTTABLE_H */
