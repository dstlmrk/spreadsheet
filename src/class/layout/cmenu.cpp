#include "cmenu.h"

CMenu::CMenu() {
	m_Window = new CWindow ();
}

void CMenu::PrintMenu() const {

	bool end = false;

	CWindow::ClearWindow(0);
	PrintOptions();

	while (!end) {

		int c;

		while( c=getch() ) {

			if (c == KEY_F(1)) {
				CWindow::ClearWindow(6);
				PrintOptions();		
				break;
			}

			if (c == KEY_F(2)) {

				// class, where is processed input
				CMove process;

				if (!process.Process()) {
					end = true;
					break;
				}
				// after end of process it prints options again
				PrintOptions();	
				break;
			}

			if (c == KEY_F(3)) {
				CHelp::PrintHelp();
				break;
			}

			if (c == KEY_F(4)) {
				end = true;
				break;
			}
		}
	}
}

void CMenu::PrintOptions() const {

	CWindow::ClearWindow(0);

	init_pair (COLOR1, COLOR_WHITE,  COLOR_BLACK);

	// set bold font and color 1
	attron (A_BOLD);
	attron (COLOR_PAIR(COLOR1));
	// row, column, string
	mvaddstr (3, 7, "Welcome to the SIMPLE SPREADSHEET");
	attroff (A_BOLD);

	mvaddstr (4, 7, "by Marek Dostal");

	mvaddstr (6, 7, "MAIN MENU:");

	attron (A_BOLD);  
	mvaddstr (8, 15,  "[F2] - NEW TABLE ");
	attroff (A_BOLD);
	mvaddstr (9, 15,  "[F3] - HELP    ");
	mvaddstr (10, 15, "[F4] - QUIT    ");
}

CMenu::~CMenu() {
	delete m_Window;
}
