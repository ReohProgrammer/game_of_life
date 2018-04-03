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
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
/*-------------------------------------------------------------------*
*    GLOBAL VARIABLES                                                *
*--------------------------------------------------------------------*/
/* Control flags */
#define DEBUG

/* Global constants */

#define MAX_HEIGHT 40
#define MAX_WIDTH 40
#define LONELINESS 2
#define OVERPOPULATION 4
#define STYLE 

enum{DEAD,ALIVE};

/* Global variables */

/* Global structures */
struct cell {
int current;
int future;
};
/*-------------------------------------------------------------------*
*    FUNCTION PROTOTYPES                                             *
*--------------------------------------------------------------------*/
int print_playground(struct cell grid[MAX_HEIGHT][MAX_WIDTH]);
int calc_future(struct cell grid[MAX_HEIGHT][MAX_WIDTH]);
int count_neighbor(struct cell grid[MAX_HEIGHT][MAX_WIDTH], int i, int j);
int copy_future(struct cell grid[MAX_HEIGHT][MAX_WIDTH]);