#include "cwindow.h"

CWindow::CWindow() {
	initscr();
	cbreak ();
	noecho ();
	start_color ();
	keypad (stdscr, TRUE);
	PrintFooter();
}

void CWindow::PrintFooter() {
	// print hoziontal line
	mvhline(LINES-3, 0, ACS_HLINE, COLS);
	mvaddstr(LINES-2, 5, "COPYRIGHT - Marek Dostal (c) - BI-PA2 project - 2014 ");
	mvaddstr(LINES-2, COLS-34, "[F1] - MAIN MENU, [F4] - QUIT");
}

void CWindow::ClearWindow(const int from) {
	// returns number of rows
	int rows = getmaxy ( stdscr );

	for ( int i = from; i < rows; i++ ) {
		// set cursor
		move ( i, 0 );
		// clear from cursor to end of line 
		clrtoeol ();
	}

	// print edges (row, column, char, length)
	mvhline(0, 1, ACS_HLINE, 120);
	mvhline(26, 1, ACS_HLINE, 120);
	mvvline(1, 1, ACS_VLINE, 25);
	mvvline(1, 121, ACS_VLINE, 25);
	// print corners
	mvhline(0, 121, ACS_URCORNER, 1);
	mvhline(26, 121, ACS_LRCORNER, 1);
	mvhline(0, 1, ACS_ULCORNER, 1);
	mvhline(26, 1, ACS_LLCORNER, 1);

	// cursor does not blink
	curs_set(0);

	PrintFooter();
}

void CWindow::FooterForHelp() {
	// set of color combination
	init_pair (COLOR2, COLOR_YELLOW,  COLOR_BLACK);    
	attron (COLOR_PAIR(COLOR2));
	mvaddstr(LINES-2, COLS-62, "[F3] - BACK TO SAVED TABLE,");
	attroff(COLOR_PAIR(COLOR2));
}

void CWindow::FooterForSave() {
	// set of color combination
	init_pair (COLOR2, COLOR_YELLOW,  COLOR_BLACK);    
	attron (COLOR_PAIR(COLOR2));
	mvaddstr(LINES-2, COLS-28, "[ENTER] - SAVE THE CELL");
	attroff (COLOR_PAIR(COLOR2));
}

void CWindow::FooterForInput() {
	mvaddstr(LINES-2, COLS-59, "[ENTER] - EDIT THE CELL,");
}

void CWindow::ClearFooter() {
	mvhline(LINES-2, COLS-70, ' ', 70);
}

void CWindow::SetCursorToStart() {
	// set new position for cursor
	move(7,14);
	// cursor will be more visible
	curs_set(2);
}

void CWindow::SetCursor(const int x, const int y) {
	// set new position for cursor
	move(x,y);
	// cursor will be more visible
	curs_set(2);
}

CWindow::~CWindow() {
	erase (); 
	refresh ();
	endwin ();
}
