#include "cmove.h"

CMove::CMove() {
	m_PrintTable = new CPrintTable();
	// udava souradnice leveho horniho rohu tabulky
	table_x = 'A';
	table_y = 0;
	// udava aktualni pozici bunky
	cell_x  = 'A';
	cell_y  = 0;
	// udava souradnice na obrazovce
	row     = 7;
	column  = 14;
}

void CMove::SetInitial() {
	table_x = 'A';
	table_y = 0;
	cell_x  = 'A';
	cell_y  = 0;
	row     = 7;
	column  = 14;
}

bool CMove::Process() {
	m_PrintTable->Table(table_x, table_y, cell_x, cell_y);
	CWindow::SetCursorToStart();
	bool help = false;
	int c;

	while( c=getch() ) {

		if (c == KEY_F(1)) {
			// call main menu
			return true;
		}

		if (c == KEY_F(3)) {
			// work with help
			if (!help) {
				// help is turn on
				help = true;
				CWindow::ClearWindow(0);
				CHelp::PrintHelp();
				CWindow::FooterForHelp();
			} else {
				// help is turn off
				help = false;
				SetInitial();
				m_PrintTable->Table(table_x,table_y, cell_x, cell_y);
				CWindow::SetCursorToStart();
			}
		}

		if (c == KEY_F(4)) {
			// regular end
			return false;
		}

		if (c == KEY_UP && help == false) {
			SetPosition(0);
		}

		if (c == KEY_DOWN && help == false) {
			SetPosition(1);
		}

		if (c == KEY_LEFT && help == false) {
			SetPosition(2);
		}

		if (c == KEY_RIGHT && help == false) {
			SetPosition(3);
		}

		// if help is off, it can continue
		if (c == '\n' && help == false) {
			m_PrintTable->NewInput(cell_x, cell_y);
			m_PrintTable->Table(table_x,table_y, cell_x, cell_y);
		}
	}
	return true;
}

void CMove::SetPosition(const int i) {
	// move to UP
	if (i==0) {
		if (row!=7) {
			row = row - 2;
			cell_y-=1;
		} else {
			if (table_y!=0) {
				table_y-=1;
				cell_y-=1;
			}
		}
	// move to DOWN
	} else if (i==1) {
		if (row!=25) {
			row = row + 2;
			cell_y+=1;
		} else {
			if (table_y!=999999) {
				table_y+=1;
				cell_y+=1;
			}
		}
	// move to LEFT
	} else if (i==2) {
		if (column!=14) {
			column  = column - 12;
			cell_x-=1;
		} else {
			if (table_x!='A') {
				table_x-=1;
				cell_x-=1;
			}
		}
	// move to RIGHT
	} else {
		if (column!=110) {
			column  = column + 12;
			cell_x+=1;
		} else {
			if (table_x!='R') {
				table_x+=1;
				cell_x+=1;
			}
		}
	}

	m_PrintTable->Table(table_x,table_y, cell_x, cell_y);
	CWindow::SetCursor(row, column);
}

CMove::~CMove() {
	delete m_PrintTable;
}
