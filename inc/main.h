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

/*	Error msg	*/
# define BADARG "Expected a non empty single argument (use quotes if needed)"
# define OVFLW_FACTO "OVERFLOW while calculating factorial"
# define FILE_PB "Cannot open/create file with name: "


/*	functions prototypes	*/
bool	input_prep(int argc, char **argv, unsigned long long int *len, unsigned long long int *net_words_nb);
void	gen_word(char *s, int start, int end, int fd);
int		get_a_file_fd(void);
#endif