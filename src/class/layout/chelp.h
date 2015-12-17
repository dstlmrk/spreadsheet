#ifndef CHELP_H
#define CHELP_H

#include <ncurses.h>

#include "./cwindow.h"

/*!
 * \class CHelp
 * \brief Print the help.
 *
 * \fn CHelp::CHelp
 * \brief Empty constructor.
 *
 * \fn CHelp::~CHelp
 * \brief Empty destructor.
 *
 * \fn CMenu::PrintHelp
 * If the user wants to see a help, PrintHelp prints it.
 * \brief Method for printing help.
 */

class CHelp {
public:
	            CHelp     (void);
	            ~CHelp    (void);
	static void PrintHelp (void);
};

#endif /* CHELP_H */
