#ifndef MAIN_H
# define MAIN_H

/*	libs includes	*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

/*	data	*/
#define DICO_PATH "data/french_dico_utf8.txt"

/*	Error msg	*/
# define BADARG "Expected a non empty single argument (use quotes if needed)"
# define OVFLW_FACTO "OVERFLOW while calculating factorial"
# define FILE_PB "Cannot open/create file with name: "

/*	functions prototypes	*/
bool	input_prep(int argc, char **argv, unsigned long long int *len, unsigned long long int *net_words_nb);
int		get_a_file_fd(void);

/*	algo	*/
void	gen_word(char *s, int start, int end, char **dico, int *matches);

/*	dico	*/
bool	search_in_dico(char **dico, char *entry);
void	print_dico(char **dico);
void	free_dico(char **dico);
char	**get_a_dico(void);

#endif