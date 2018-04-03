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
*    FUNCTIONS                                                     *
**********************************************************************/
int print_playground(struct cell grid[MAX_HEIGHT][MAX_WIDTH])
{
	int i,j;
	
	move(0,0);
	
	for (i = 0; i < MAX_HEIGHT; i++) 
	{
        for (j = 0; j < MAX_WIDTH; j++) 
		{
			if(grid[j][i].current == ALIVE)
			{	 
				 #ifdef STYLE
				 printw("o");
				 #else
				 printf("o");
				 #endif
			}
			else if(grid[j][i].current == DEAD)
			{
				#ifdef STYLE
				printw(".");
				#else
				printf(".");
				#endif
			}
        }
		#ifdef STYLE
        printw("\n");
		#else
		printf("\n");
		#endif
    }
	#ifdef STYLE
	refresh();
	#else
	printf("\n");
	#endif
}
/*********************************************************************
;	F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: print_playground
; DESCRIPTION: prints out the playground that consists of dots and o's
;	Input:
;	Output:
;  Used global variables:
; REMARKS when using this function:
;*********************************************************************/
int calc_future(struct cell grid[MAX_HEIGHT][MAX_WIDTH])
{
	int i,j;
	int calculation;
	
	//problem is in this function
	
	for (i = 0; i < MAX_HEIGHT; i++) 
	{
        for (j = 0; j < MAX_WIDTH; j++) 
		{
			calculation = count_neighbor(grid,j,i);
			#ifndef STYLE
			printf("%d ",calculation);
			#endif
			if(grid[j][i].current == ALIVE) //if cell is alive
			{
				if(calculation >= LONELINESS && calculation < OVERPOPULATION) //if cell is more than 2 and less than 4
				{
					grid[j][i].future = ALIVE;
				}
				else if(calculation < LONELINESS) //if cell is less than 2
				{
					grid[j][i].future = DEAD;
				}
				else if(calculation >= OVERPOPULATION) //if cell is 4 or more than 4
				{
					grid[j][i].future = DEAD;
				}
			}
			else if(grid[j][i].current == DEAD) //if cell is dead
			{
				if(calculation > LONELINESS && calculation < OVERPOPULATION) //if cell is lower than 4
				{
					grid[j][i].future = ALIVE;
				}
			}
			else 
			{
				grid[j][i].future = ALIVE;
			}
		}
		#ifndef STYLE
		printf("\n");
		#endif
	}
}
/*********************************************************************
;	F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: calc_future
; DESCRIPTION: calculates the future of the table
;	Input:
;	Output:
;  Used global variables:
; REMARKS when using this function:
;*********************************************************************/
int count_neighbor(struct cell grid[MAX_HEIGHT][MAX_WIDTH], int j, int i)
{
	int calculation;
	/*if(i <= MAX_WIDTH)
	{
		calculation = grid[j][i-1].current + grid[j][i+1].current + grid[j-1][i-1].current + grid[j-1][i].current + grid[j-1][i+1].current;
	}*/
	if(i == 0 && j == 0)
	{
		calculation = 
		grid[j][i+1].current + 
		grid[j+1][i+1].current + 
		grid[j+1][i].current;
	}
	else if(i == MAX_WIDTH-1 && j == MAX_HEIGHT-1)
	{
		calculation = 
		grid[j][i-1].current + 
		grid[j-1][i-1].current + 
		grid[j-1][i].current;
	}
	else if(i == 0 && j == MAX_HEIGHT-1)
	{
		calculation = 
		grid[j][i+1].current + 
		grid[j-1][i+1].current + 
		grid[j-1][i].current;
	}
	else if(i == MAX_WIDTH-1 && j == 0)
	{
		calculation = 
		grid[j+1][i].current + 
		grid[j+1][i-1].current + 
		grid[j][i-1].current;
	}
	else if(i == MAX_WIDTH-1)
	{
		calculation = 
		grid[j-1][i].current + 
		grid[j-1][i-1].current + 
		grid[j][i-1].current + 
		grid[j+1][i-1].current + 
		grid[j+1][i].current;
	}
	else if(j == MAX_HEIGHT-1)
	{
		calculation = 
		grid[j][i-1].current + 
		grid[j-1][i-1].current + 
		grid[j-1][i].current + 
		grid[j-1][i+1].current + 
		grid[j][i+1].current;
	}
	else if(i == 0)
	{
		calculation = 
		grid[j][i+1].current + 
		grid[j+1][i+1].current + 
		grid[j+1][i].current + 
		grid[j-1][i+1].current + 
		grid[j-1][i].current;
	}
	else if(j == 0)
	{
		calculation = 
		grid[j][i-1].current + 
		grid[j+1][i-1].current + 
		grid[j+1][i].current + 
		grid[j+1][i+1].current + 
		grid[j][i+1].current;
	}
	else 
	{
		calculation = 
		grid[j+1][i-1].current + 
		grid[j+1][i].current + 
		grid[j+1][i+1].current + 
		grid[j][i+1].current + 
		grid[j-1][i+1].current + 
		grid[j-1][i].current + 
		grid[j-1][i-1].current;
	}
	return(calculation);
}

/*********************************************************************
;	F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: count_neighbor
; DESCRIPTION: counts the amount of neighbors each cell has
;	Input:
;	Output:
;  Used global variables:
; REMARKS when using this function:
;*********************************************************************/
int copy_future(struct cell grid[MAX_HEIGHT][MAX_WIDTH])
{	
	int i, j;
	
	for (i = 0; i < MAX_HEIGHT; i++) 
	{
        for (j = 0; j < MAX_WIDTH; j++) 
		{
			grid[j][i].current = grid[j][i].future;
		}
	}
}
/*********************************************************************
;	F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: copy_future
; DESCRIPTION: Copies the future table onto the current one
;	Input:
;	Output:
;  Used global variables:
; REMARKS when using this function:
;*********************************************************************/
