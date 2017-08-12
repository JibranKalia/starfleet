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
void	saveTheSequoia(struct s_node **root);

=======
char *getXor(char *a, char *b);
int toInt(char *bits);
>>>>>>> 4starfleet/master

/*--------------------------------
  ?? test function used in main 
  --------------------------------*/
<<<<<<< HEAD
struct s_node *genMinHeap(unsigned seed); //generate a min heap
void printBinaryTree(struct s_node * t); //print a binary tree

=======
int checkBinary(char *str);
>>>>>>> 4starfleet/master

/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
