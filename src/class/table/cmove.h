#ifndef CMOVE_H
#define CMOVE_H

#include <ncurses.h>
#include "../layout/cprinttable.h"
#include "../layout/chelp.h"
#include "../layout/cwindow.h"

/*!
 * \class CMove
 * \brief Provides moves on the table.
 *
 * \fn CMove::CMove
 * \brief Create initial coordinates and instance of CPrintTable.
 *
 * \fn CMove::~CMove
 * \brief Destructor.
 *
 * \fn CMove::SetInitial
 * \brief Set all coordinates to inital values.
 *
 * \fn CMove::Process
 * Read keys: UP, DOWN, LEFT, RIGHT, ENTER for move on the table. If needed, call help or quit from program.
 * @return bool, when is table is ended
 * \brief Works with moves on the table.
 *
 * \fn CMove::SetPosition
 * \param i [in] 0=UP, 1=DOWN, 2=LEFT, 3=RIGHT
 * \brief One move on the table.
 */

class CMove {

public:
	     CMove       (void);
	     ~CMove      (void);
	void SetInitial  (void);
	bool Process     (void);
	void SetPosition (const int);

private:
	//! Instance of CPrintTable, where is table and saved data.
	CPrintTable * m_PrintTable;
	//! Index of column, where is left upper corner for actual position.
	int table_x;
	//! Index of row, where is left upper corner for actual position.
	int table_y;
	//! Coordinates on the terminal window (row).
	int row;
	//! Coordinates on the terminal window (column).
	int column;
	//! Index of column, where is actual position of cursor.
	char cell_x;
	//! Index of row, where is actual position of cursor.
	int cell_y;
};

#endif /* CMOVE_H */
