#ifndef HEADER_H
# define HEADER_H

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

/*--------------------------------
  !! required structure
  --------------------------------*/
typedef struct s_info {
	int gender;
	int height;
	int hairColor;
	int eyeColor;
	int glasses;
	int tattoo;
	int piercing;
} t_info;

typedef  struct s_criminal {
	char *name;
	int  description;
} t_criminal;

/*--------------------------------
  :) function you must implement
  --------------------------------*/
int getDescription(struct s_info *info);
void sortCriminals(struct s_criminal **criminals);
struct s_criminal **findPotentialCriminals(struct s_criminal **criminals, struct s_info *info);

/*--------------------------------
  ?? test function used in main
  --------------------------------*/
struct s_criminal **getCriminals(char *filename);
void printCriminals(struct s_criminal **criminals);
struct s_info *getInfo(char *description);

/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
