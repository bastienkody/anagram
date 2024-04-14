#include "../inc/main.hpp"

void	swap(char *a, char *b)
{
	char	tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}

/*	anagramme algo	*/
void	gen_word(char *s, int start, int end, Dico *dico, uint_ll *matches)
{
	
	if (start == end && dico->searchStr(s))
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

int main(int argc, char **argv)
{
	uint_ll	len, net_words_nb, matches = 0;
	if (input_prep(argc, ++argv, &len, &net_words_nb) == false) {return 2;}

	Dico	*nomsCommuns = new Dico();
	if (nomsCommuns->init(DICO_PATH) == false) {return 2;}
	else	{std::cout << "Dico noms communs ready" << std::endl;}

	gen_word(*argv, 0, len - 1, nomsCommuns, &matches);
	std::cout << "matches:\t" << matches << std::endl;

	delete nomsCommuns;
	return 0;
}
