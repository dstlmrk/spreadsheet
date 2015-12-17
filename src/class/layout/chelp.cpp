#include "chelp.h"

CHelp::CHelp() {}

void CHelp::PrintHelp() {
	CWindow::ClearWindow(0);

	attron (A_BOLD);
	mvaddstr (2, 7,  "HELP:");
	mvaddstr (5, 7,  "  1) CELLS and COORDINATES");
	mvaddstr (10, 7, "  2) INPUT and OUTPUT");
	mvaddstr (15, 7, "  3) EXAMPLES OF CORRECT INPUTS");
	mvaddstr (20, 7, "  4) EXAMPLES OF INCORRECT INPUTS");
	attroff (A_BOLD);

	mvaddstr (4, 7,  "  Welcome to the simple SPREADSHEET. Work with this program is very friendly.");
	mvaddstr (6, 7,  "      - In spreadsheet every cell has a specific name that allows you to directly address each cell.");
	mvaddstr (7, 7,  "      - For example, the cell in column A and row 1 is named A1.");
	mvaddstr (8, 7,  "      - These cell names can be used in expressions and commands in order to address");
	mvaddstr (9, 7,  "        the content of the corresponding cell.");
	mvaddstr (11, 7, "      - In the spreadsheet cells you can enter integers or strings.");
	mvaddstr (12, 7, "      - Addition, subtraction, multiplication and division are supported by this spreadsheet.");
	mvaddstr (13, 7, "      - If you want to input a string, please make it in quotation marks.");
	mvaddstr (14, 7, "      - Output supports decimal numbers.");
	mvaddstr (16, 7, "      - 5+1");
	mvaddstr (17, 7, "      - (34+45)/15");
	mvaddstr (18, 7, "      - (B2+B3+B4)*(15/3)");
	mvaddstr (19, 7, "      - \"Any character\"");

	mvaddstr (21, 7, "      - 14.223");
	mvaddstr (22, 7, "      - 3B+4V");
	mvaddstr (22, 7, "      - 35+5)");
	mvaddstr (23, 7, "      - \"Any character");

}

CHelp::~CHelp() {}
