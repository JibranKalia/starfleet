#ifndef HEADER_H
# define HEADER_H

<<<<<<< HEAD
/*--------------------------------
  !! required structure
  --------------------------------*/
struct s_node {
	int value;
	struct s_node *right;
	struct s_node *left;
};
=======
#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

/*--------------------------------
  !! required structure
  --------------------------------*/
>>>>>>> 4starfleet/master


/*--------------------------------
  :) function you must implement
  --------------------------------*/
<<<<<<< HEAD
void insertMonkey(struct s_node **root, struct s_node *monkey);

=======
int getPlace(unsigned int parkingRow, int pos);
>>>>>>> 4starfleet/master

/*--------------------------------
  ?? test function used in main 
  --------------------------------*/
<<<<<<< HEAD
struct s_node *genMaxHeap(unsigned seed);
void printBinaryTree(struct s_node *t);
struct s_node *randomMonkey(void);
=======
>>>>>>> 4starfleet/master


/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
