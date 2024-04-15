#ifndef MAIN_H
# define MAIN_H

//	CPP libs
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

#include "../src/Dico.hpp"
class Dico;

/*	clibs includes	*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>

typedef unsigned long long int uint_ll;

#define DICO_PATH		"data/french_dico_utf8.txt"
#define PRENOMS_PATH	"data/prenoms2.txt"
#define SEP 			"##################################################################"

/*	Error msg	*/
# define BADARG 		"Expected a non empty single argument (use quotes if needed)"
# define OVFLW_FACTO 	"OVERFLOW while calculating factorial"
# define FILE_PB 		"Cannot open/create file with name: "

/*	functions prototypes	*/
bool	input_prep(int argc, char **argv, uint_ll *len, uint_ll *net_words_nb);

#endif
