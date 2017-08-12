#ifndef HEADER_H
# define HEADER_H

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include <stdbool.h>
#include <time.h>

/*--------------------------------
  !! required structure
  --------------------------------*/
	typedef struct s_stone {
		int size;
		struct s_stone *next;
	} t_stone;


/*--------------------------------
  :) function you must implement
  --------------------------------*/
//stone is a pointer to the first
void sortStones(struct s_stone **stone);


/*--------------------------------
  ?? test function used in main
  --------------------------------*/
struct s_stone *genRandomStoneList(int n);
void printStone(struct s_stone *stone);
struct s_stone *createStone(int size);
void exitWithMsg(char *msg);


/*--------------------------------
  &  your own other function
  --------------------------------*/

#endif
