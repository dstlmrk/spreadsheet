#ifndef CMENU_H
#define CMENU_H

#include <ncurses.h>
#include "./cwindow.h"
#include "../table/cmove.h"
#include "./chelp.h"

/*!
 * \class CMenu
 * \brief Print the main menu.
 *
 * \fn CMenu::CMenu
 * \brief Constructor.
 *
 * \fn CMenu::~CMenu
 * \brief Empty destructor.
 *
 * \fn CMenu::PrintMenu
 * Calls private method PrintOptions for printing the options and works with input keys.
 * If the user wants to create new table, CMenu creates new instance of CMove and hand over the control.
 * \brief Method for printing the main menu.
 *
 * \fn CMenu::PrintOptions
 * \brief Method for printing options.
 */

class CMenu {

public:
	     CMenu     (void);
	     ~CMenu    (void);
	void PrintMenu (void) const;

private:
	void PrintOptions(void) const;

	//! Instance of CWindow, whose starts ncurses.
	const CWindow * m_Window;
};

#endif /* CMENU_H */
