#ifndef CTABLE_H
#define CTABLE_H

#include <sstream>
#include <cstring>
#include <map>
#include <ncurses.h>
#include <stdlib.h>

#include "../cell/ccell.h"
#include "../cell/cstringcell.h"
#include "../cell/cintcell.h"

#define LEX_NULL 0
#define LEX_ERR  1
#define LEX_INT  2
#define LEX_ADD  3
#define LEX_SUB  4
#define LEX_MUL  5
#define LEX_DIV  6
#define LEX_LPA  7
#define LEX_RPA  8

using namespace std;

/*!
 * \class CTable
 * \brief Print the table and all data from it.
 *
 * \fn CTable::CTable
 * \brief Empty constructor.
 *
 * \fn CTable::~CTable
 * \brief Destructor.
 *
 * \fn CTable::GetExpression
 * \param cell_x [in] coordinate (column)
 * \param cell_y [in] coordinate (row)
 * @return exact expression from input
 * \brief Get expression from cell.
 *
 * \fn CTable::GetOutput
 * \param cell_x [in] coordinate (column)
 * \param cell_y [in] coordinate (row)
 * @return string for display
 * \brief Get output for display in the table from cell.
 *
 * \fn CTable::NewCell
 * \param s [in] new expression for cell
 * \param cell_x [in] coordinate (column)
 * \param cell_y [in] coordinate (row)
 * @return true, if input expression is correct and cell is saved, else false
 * \brief Makes new cells and expressions in them.
 *
 * \fn CTable::Find
 * \param cell_x [in] coordinate (column)
 * \param cell_y [in] coordinate (row)
 * @return true, if cell exists, else false
 * \brief Search, if cell exists.
 *
 * \fn CTable::Delete
 * \param cell_x [in] coordinate (column)
 * \param cell_y [in] coordinate (row)
 * \brief Delete cell and its connections.
 *
 * \fn CTable::Type
 * \param cell_x [in] coordinate (column)
 * \param cell_y [in] coordinate (row)
 * @return type of cell (STRING or NUMBER)
 * \brief Get type of cell.
 *
 * \fn CTable::Parse
 * \param s [inout] expression for parse, edit and control
 * \param cell_x [in] coordinate (column)
 * \param cell_y [in] coordinate (row)
 * @return const int - \n 
 	when 0 => input expression is wrong,\n
 	when 1 => input expression is STRING,\n
 	when 2 => input expression is NUMBER
 * \brief Detects, if input expression is number or string.
 *
 * \fn CTable::AddLink
 * Here is making new connections between cells. It is for control, if somewhere is deadlock.
 * \param cell_x [in] coordinate (column), where data should be printed
 * \param cell_y [in] coordinate (row), where data should be printed
 * \param _cell_x [in] coordinate (column), where data are stored
 * \param _cell_y [in] coordinate (row), where data are stored
 * \brief Making connections between cells.
 *
 * \fn CTable::DelLinks
 * \param cell_x [in] coordinate (column)
 * \param cell_y [in] coordinate (row)
 * \brief Delete all conections, where is this cell as PRINT.
 *
 * \fn CTable::CheckLinks
 * Checks, when PRINT cell is somewhere on the way of cell, where should be stored data. This method uses recursion.
 * \param cell_x [in] coordinate (column), where data should be printed
 * \param cell_y [in] coordinate (row), where data should be printed
 * \param _cell_x [in] coordinate (column), where data are stored
 * \param _cell_y [in] coordinate (row), where data are stored
 * \brief Checks deadlock between cells.
 *
 * \fn CTable::StringToCharArray
 * \param s [in] string for convert
 * @return const char array
 * \brief Converts string to char array.
 *
 * \fn CTable::DoubleToString
 * \param d [in] double for convert
 * @return const char array
 * \brief Converts double to string
 *
 * \fn CTable::NextToken
 * Read next token (number, coordinate, operator, bracket)
 * NextToken, Factor and Expr are adapted from example presented on EDUx.
 * See link https://edux.fit.cvut.cz/courses/BI-PA1/_media/seminars/09/09-examples.tgz for original version.
 * \param init [in] two status (true=making new connections and new cells, false=only calculating)
 * \param str [in] string, where is whole expression
 * \param i [inout] pointer shows actual position in string
 * \param val [inout] result
 * \param _cell_x [in] coordinate (column), where this method calculate
 * \param _cell_y [in] coordinate (row), where this method calculate
 * \brief Read next token.
 *
 * \fn CTable::Factor
 * NextToken, Factor and Expr are adapted from example presented on EDUx.
 * See link https://edux.fit.cvut.cz/courses/BI-PA1/_media/seminars/09/09-examples.tgz for original version.
 * \param init [in] two status (true=making new connections and new cells, false=only calculating)
 * \param str [in] string, where is whole expression
 * \param i [inout] pointer shows actual position in string
 * \param val [inout] result
 * \param _cell_x [in] coordinate (column), where this method calculate
 * \param _cell_y [in] coordinate (row), where this method calculate
 * \brief Allocate work to brackets.
 *
 * \fn CTable::Expr
 * NextToken, Factor and Expr are adapted from example presented on EDUx.
 * See link https://edux.fit.cvut.cz/courses/BI-PA1/_media/seminars/09/09-examples.tgz for original version.
 * This method, Factor and NextToken have two status.
 * If it is only calculating or calculating and making new connections between cells.
 * \param init [in] two status (true=making new connections and new cells, false=only calculating)
 * \param str [in] string, where is whole expression
 * \param i [inout] pointer shows actual position in string
 * \param res [inout] result
 * \param whenToReturn [in] when this method have to end up
 * \param _cell_x [in] coordinate (column), where this method calculate
 * \param _cell_y [in] coordinate (row), where this method calculate
 * \brief Calculate number expressions.
 */

class CTable {

public:
	             CTable();
	             ~CTable();
	const string GetExpression (const char cell_x, const int cell_y);
	const string GetOutput     (const char cell_x, const int cell_y);
	bool         NewCell       (const string &, const char cell_x, const int cell_y);

private:
	bool         Find              (const char cell_x, const int cell_y);
	void         Delete            (const char cell_x, const int cell_y);
	const string Type              (const char cell_x, const int cell_y);
	const int    Parse             (string & s, const char cell_x, const int cell_y);
	bool         AddLink           (const char cell_x,const int cell_y,const char _cell_x,const int _cell_y);
	void         DelLinks          (const char cell_x, const int cell_y);
	bool         CheckLinks        (const char cell_x, const int cell_y, const char _cell_x, const int _cell_y);
	const char * StringToCharArray (const string & s);
	const string DoubleToString    (const double & d);
	// NextToken, Factor and Expr are adapted from example presented on EDUx
	// see link https://edux.fit.cvut.cz/courses/BI-PA1/_media/seminars/09/09-examples.tgz for original version
	int          NextToken (bool init, string str, int & i, double * val, char cell_x, int cell_y);
	int          Factor    (bool init, string str, int & i, double * val, char cell_x, int cell_y);
	int          Expr      (bool init, string str, int & i, double * res, int whenToReturn, char cell_x, int cell_y);

	//! All cells (CCell) are stored in this map. Cell acces is via index [column][row].
	map <char, map <int, const CCell*> > m_Data;
	//! All conections between cells, first pair is cell, whose is PRINTED, in second coordinates are stored DATA.
	multimap< pair<char,int>, pair<char,int> > m_links;
};

#endif /* CTABLE_H */
