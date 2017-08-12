#ifndef HEADER_H
# define HEADER_H

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include <time.h>

/*--------------------------------
  !! required structure
  --------------------------------*/


/*--------------------------------
  :) function you must implement
  --------------------------------*/
void countSort(unsigned char *utensils, int n);


/*--------------------------------
  ?? test function used in main
  --------------------------------*/
unsigned char *genRandomUstensils(int *n);
void printUtensils(unsigned char *utensils, int n);

/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
