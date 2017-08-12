#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/
<<<<<<< HEAD
struct s_node {
	char		      c;
	unsigned int	isWord:1;
	struct        s_node	**child;
};

struct s_trie {
	struct s_node *node;
};
=======
>>>>>>> 4starfleet/master


/*--------------------------------
  :) function you must implement
  --------------------------------*/
<<<<<<< HEAD
struct s_trie *createTrie(char **dictionary);
char *understand(char *word, struct s_trie *trie);

=======
unsigned int clearPlace(unsigned int parkingRow, int pos);
>>>>>>> 4starfleet/master

/*--------------------------------
  ?? test function used in main 
  --------------------------------*/
<<<<<<< HEAD
extern char *g_dict[];

char *understandAll(char *sentence, struct s_trie *trie);
=======
>>>>>>> 4starfleet/master


/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
