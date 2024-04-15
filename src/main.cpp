#include "../inc/main.hpp"

/*	Next_permutations rearrange input to get the next greater lexycographic 
	permutation : to get all of them, you might sort it before !
	It returns false when it cannot get a greater one	*/
void gen_word(std::string s, std::vector<std::string> & words)
{
	std::sort(s.begin(), s.end());

	do		{words.push_back(s);}
	while	(std::next_permutation(s.begin(), s.end()));
}

std::vector<std::string>	get_matches(std::vector<std::string> & words, Dico *dico)
{
	std::vector<std::string>	matches;

	for (std::vector<std::string>::iterator it = words.begin(); it != words.end(); ++it)
		if (dico->searchStr(*it) == true)
			matches.push_back(*it);
	return matches;
}

void	printMatches(std::vector<std::string> & matches, std::string type)
{
	std::cout << type << ": " << matches.size() << " matches." << std::endl;
	for (std::vector<std::string>::iterator it = matches.begin(); it != matches.end(); ++it)
		std::cout << *it << std::endl;
	std::cout << SEP << std::endl;
}

int main(int argc, char **argv)
{
	uint_ll	len, net_words_nb;
	if (input_prep(argc, ++argv, &len, &net_words_nb) == false) {return 2;}

	Dico	*nomsCommuns = new Dico();
	if (nomsCommuns->init(DICO_PATH) == false) {return 2;}
	else	{std::cout << "Dico noms communs ready" << std::endl;}

	Dico	*prenoms = new Dico();
	if (prenoms->init(PRENOMS_PATH) == false) {return 2;}
	else	{std::cout << "Dico prenoms ready" << std::endl << SEP << std::endl;}

	std::vector<std::string>	words;
	gen_word(*argv, words);
	std::cout << words.size() << " words generated" << std::endl << SEP << std::endl;

	std::vector<std::string>	prenoms_matches = get_matches(words, prenoms);
	printMatches(prenoms_matches, "Prenoms");

	std::vector<std::string>	noms_matches = get_matches(words, nomsCommuns);
	printMatches(noms_matches, "Noms communs");

	delete nomsCommuns;
	delete prenoms;
	return 0;
}
