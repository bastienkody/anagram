#include "../inc/main.hpp"

void	swap(char *a, char *b)
{
	char	tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}

/*	anagramme algo	
	Pour otpi il va falloir : 
		1 - generer tous les mots dans un [file|vector|container] sans check de dico
		2 - sort + uniq du container
			au lieu de sort/uniq a posterio, on peut check avant d'insert si le mot
			est deja present
		3 - comparaision du container avec le dico
	Il faudrait aussi appliquer des filtres a l'etape 1 (ie: ko if 3 consonnes consecutives etc)
	L'etape 3 doit etre ameliore (ie: si aucun mot en "jod", ne pas chercher "jodi" ou "jodaer" later)
*/
void	gen_word(char *s, int start, int end, Dico *nomCommuns, Dico *prenoms, uint_ll *matches)
{
	if (start == end && ( nomCommuns->searchStr(s) ||  prenoms->searchStr(s) ) )
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
			gen_word(s, start + 1, end, nomCommuns, prenoms, matches);
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

	Dico	*prenoms = new Dico();
	if (prenoms->init(PRENOMS_PATH) == false) {return 2;}
	else	{std::cout << "Dico prenoms ready" << std::endl;}

	std::cout << SEP << std::endl;
	gen_word(*argv, 0, len - 1, nomsCommuns, prenoms, &matches);
	std::cout << SEP << std::endl << "matches:\t" << matches << std::endl;

	delete nomsCommuns;
	delete prenoms;
	return 0;
}
