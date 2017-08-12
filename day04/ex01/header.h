#ifndef HEADER_H
# define HEADER_H
<<<<<<< HEAD
=======
#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
>>>>>>> 4starfleet/master

/*--------------------------------
  !! required structure
  --------------------------------*/
<<<<<<< HEAD
struct s_node {
	int value;
	struct s_node *right;
	struct s_node *left;
};
=======
>>>>>>> 4starfleet/master


/*--------------------------------
  :) function you must implement
  --------------------------------*/
<<<<<<< HEAD
struct s_node *createBST(int *arr, int n);

=======
char *getAnd(char *a, char *b);
char *getOr(char *a, char *b);
int toInt(char *bits);
>>>>>>> 4starfleet/master

/*--------------------------------
  ?? test function used in main 
  --------------------------------*/
<<<<<<< HEAD
void printBinaryTree(struct s_node * t); //print a binary tree

=======
int checkBinary(char *str);
>>>>>>> 4starfleet/master

/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
