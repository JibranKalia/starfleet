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

struct s_info {
	int min;        // the minimum value in the tree
	int max;        // the max value in the tree
	int elements;   // the number of nodes in the tree
	int height;     // the height of the tree
	int isBST;      // 0 = FALSE, 1 = TRUE
	int isBalanced; // 0 = FALSE, 1 = TRUE
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
struct s_info   getInfo(struct s_node *root);


/*--------------------------------
  ?? test function used in main
  --------------------------------*/
void printBinaryTree(struct s_node * t); //print a binary tree
struct s_node *genRandomBinaryTree(unsigned seed); //gen a random binary tree
void    printTreeInfo(struct s_info info); //print the info from a binary tree


/*--------------------------------
  &  your own other stuff
  --------------------------------*/

=======
char *getSum(char *a, char *b);
int toInt(char *bits);

/*--------------------------------
  ?? test function used in main 
  --------------------------------*/
int checkBinary(char *str);

/*--------------------------------
  &  your own other function
  --------------------------------*/


>>>>>>> 4starfleet/master
#endif
