#ifndef CWINDOW_H
#define CWINDOW_H

#include <ncurses.h>

//! White(1), yellow(2) and red(3) color
#define COLOR1 1
#define COLOR2 2
#define COLOR3 3

using namespace std;

/*!
 * \class CWindow
 * Class for creating and closing window in ncurses. CWindow is called before printing the main menu (CMenu). Class is also using for footer.
 * \brief Basic window and footer manipulation.
 *
 * \fn CWindow::CWindow
 * Initialization screen, set line baffering, no printing keys from input, turn on colors, set using keys from F1 to Fn.
 * \brief Creates the basic version of ncurses based terminal.
 *
 * \fn CWindow::~CWindow
 * Here is destroyed ncurses window.
 * \attention This operation is very important for next work in terminal!
 * \brief Destructor.
 *
 * \fn CWindow::PrintFooter
 * In the lowest of the terminal writes basic options.
 * \brief Print the footer
 *
 * \fn CWindow::FooterForHelp
 * \brief Print the edited footer, while help is printed.
 *
 * \fn CWindow::FooterForSave
 * \brief Print the edited footer, while input is activated.
 *
 * \fn CWindow::FooterForInput
 * \brief Print the edited footer, while table is waiting for operation.
 *
 * \fn CWindow::ClearFooter
 * \brief Print the footer without options.
 *
 * \fn CWindow::ClearWindow
 * \param row [in] start row, where the clearing should start
 * \brief Clear the window.
 */

class CWindow {
public:
	            CWindow          (void);
	            ~CWindow         (void);
	static void PrintFooter      (void);
	static void FooterForHelp    (void);
	static void FooterForSave    (void);
	static void FooterForInput   (void);
	static void ClearFooter      (void);
	static void ClearWindow      (const int row);
	static void SetCursorToStart (void);
	static void SetCursor        (const int x, const int y);
};

#endif /* CWINDOW_H */
