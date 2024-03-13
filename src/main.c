#include "../inc/main.h"

void	swap(char *a, char *b)
{
	char	tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}

/*	anagramme algo	*/
void	gen_word(char *s, int start, int end, char **dico, int *matches)
{
	
	if (start == end && search_in_dico(dico, s))
	{
		++(*matches);
		write(1, s, strlen(s));
		write(1, "\n", 1);
	}
	else 
	{
		for (int i = start; i <= end; i++) 
		{
			swap(s + start, s + i);
			gen_word(s, start + 1, end, dico, matches);
			swap(s + start, s + i);
		}
	}
}

int	main(int argc, char ** argv, __attribute__((unused))char ** envp)
{
	unsigned long long int	len;
	unsigned long long int	net_words_nb;
	char					**dico = NULL;
	int						matches = 0;

	if (!(dico = get_a_dico()))
		printf("Dico is null from main")








	//if (!input_prep(argc, ++argv, &len, &net_words_nb) || (printf("uploading french dico ...\n") && !(dico = get_a_dico())))
		//return (2);
	//printf("french dico uploaded.\nanagrams generation ...\n\n");
	//gen_word(*argv, 0, len - 1, dico, &matches);
	//printf("\nmatches found : %i\n", matches);

	return (free_dico(dico), 0);
}

