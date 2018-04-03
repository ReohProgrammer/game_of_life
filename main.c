/***************************************************************************
 *   Copyright (C) $Year$ by $Author: e1401175 $   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

/*********************************************************************
*
* 1.  NAME
*     $Source$ 
* 2.  DESCRIPTION
*
* 6.  VERSIONS
*       Original:
*         $Date: 2016-12-13 11:41:19 +0200 (Tue, 13 Dec 2016) $ / $Author: e1401175 $
*
*       Version history:
*       
*
**********************************************************************/

/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/
#include "GameOfLife.h"

/*********************************************************************
*    MAIN PROGRAM                                                      *
**********************************************************************/

int main(void)
{
	struct cell grid[MAX_HEIGHT][MAX_WIDTH]={0};
	int i=0;
	#ifdef STYLE //This is to test problems
	initscr ();
	start_color ();
    init_pair (1, COLOR_BLUE, COLOR_WHITE);
    bkgd (COLOR_PAIR (1));
	
	clear ();
	#endif
	
	while(i < (MAX_HEIGHT*MAX_WIDTH)/5)
	{
		grid[rand() % MAX_HEIGHT][rand() % MAX_WIDTH].current = ALIVE;		//"elossa" olevia soluja
		i++;		
	}
	
	i=0;
	
	while(1)
	{
		/*move(0,40);
		printw("%d",i++);
		refresh();*/
		print_playground(grid);
		calc_future(grid);
		copy_future(grid);
		sleep(1);
	}
	#ifdef STYLE
	getch ();
	endwin ();
	#endif
} /* end of main */
