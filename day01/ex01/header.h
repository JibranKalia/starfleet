#ifndef HEADER_H
# define HEADER_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*--------------------------------
  !! required structure
  --------------------------------*/
typedef struct s_node {
	char          *word;
	struct s_node *next;
} t_node;

/*--------------------------------
  :) function you must implement
  --------------------------------*/
void printReverse(struct s_node *lst);

/*--------------------------------
  ?? test function used in main 
  --------------------------------*/
struct s_node *createList(char **words, int n);

/*--------------------------------
  &  your own other function
  --------------------------------*/
void displayAll(t_node *start);

#endif
