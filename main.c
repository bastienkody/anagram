#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

// better printing
// print each letter
// calculate number of words to generate

// check input : no digit, no punctuation?, 
// then to lower

int	main(int argc, char ** argv, __attribute__((unused))char ** envp)
{
	if (argc != 2 || !++argv)
		fprintf(stderr, "Please only provide a single argument (use quotes if spaces)\n");
	printf("Input word is : \'%s\', length : %i\n", *argv, strlen(*argv));
}

