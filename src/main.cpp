#include "./class/layout/cmenu.h"

int main() {

	/*!
    * \mainpage The main page of PA2 project
    *
    * \section Description
    * Simple spreadsheet has written in C++ and <a href='http://www.gnu.org/software/ncurses/ncurses.html'>ncurses</a> as GUI. It works with basic mathematical operation. More informations in help.
    *
    * \image html screenshot.png Screenshot of Simple spreadsheet
    *
    * \section Installation
    * Simple spreadsheet doesn't require installation. The only thing you have to do is to make it.
    * \code
    *    make compile
    *    make run
    * \endcode
    *
    * This should do the job.
    *
    * \section Copyright
    *    \li &copy; Marek Dostal 2014
    *    \li Icon downloaded from <a href='https://www.iconfinder.com/icons/25018/document_office_paper_spreadsheet_icon#size=128'>iconfinder.com</a>.
    */

	CMenu menu;
	menu.PrintMenu();

	return 0;
}
