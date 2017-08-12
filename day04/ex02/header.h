#ifndef HEADER_H
# define HEADER_H

<<<<<<< HEAD
/*--------------------------------
  !! required structure
  --------------------------------*/
struct s_node {
	char	*name;
	struct s_node **children;
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
struct s_node *findParent(struct s_node *root, char *firstSpecies, char *secondSpecies);

=======
char *rightShift(char *bin, int k);
char *leftShift(char *bin, int k);
int toInt(char *bits);
>>>>>>> 4starfleet/master

/*--------------------------------
  ?? test function used in main 
  --------------------------------*/
<<<<<<< HEAD
struct s_node *getTreeOfLife(void);

=======
int checkBinary(char *str);
>>>>>>> 4starfleet/master

/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
<<<<<<< HEAD
  
=======
>>>>>>> 4starfleet/master
