#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"
<<<<<<< HEAD
#include "dictionary.c"

int main(int ac, char **av)
{
	struct s_trie *trie;

	trie = NULL;
	
	if (ac >= 2){
		/*-------------------
		  launch your test here
		  --------------------*/
		// if (!(trie = createTrie(g_dict)))
		// 	return (-1);
		// printf("%s\n", understandAll(av[1], trie));
	}else{
		printf("Usage: %s 'wo?d'\n", av[0]);
	}
=======

int main(int ac, char **av)
{
	unsigned int parkingRow;
	int pos;

	if (ac == 3 && (pos = atoi(av[2])) >= 0 && pos < 20) {
		parkingRow = atoi(av[1]);
	}else{
		printf("usage: ./clearPlace parkingRow pos\n");
		return (0);
	}
	/*-------------------
	launch your test here
	--------------------*/

	printf("New parking row: %d\n", clearPlace(parkingRow, pos));
>>>>>>> 4starfleet/master

	return (0);
}



// Function used for the test
// Don't go further :)

<<<<<<< HEAD
#define SEPARATOR " !:;,.$&<>()+*-_=\n\t"

int	isInside(char c, char *string){
	for (int i = 0; string[i]; i++){
		if (string[i] == c)
			return (1);
	}
	return (0);
}

char *understandAll(char *sentence, struct s_trie *trie) {
	char *output;
	char *token;
	char *separator = SEPARATOR;
	char *tmp;
	char *replace;

	output = strdup(sentence);
	token = strtok(output, separator);
	while(token != NULL) 
	{
		if (strchr(token, '?')) {
			if (!(replace = understand(token, trie)))
				return (NULL);
			strcpy(token, replace);
			free(replace);
		}
		tmp = token + strlen(token);
		token = strtok(NULL, separator);
		*tmp = *(sentence + (int)(tmp - output));
	}
	return (output);
}
=======
>>>>>>> 4starfleet/master
