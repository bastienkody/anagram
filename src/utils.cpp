#include "../inc/main.hpp"

//	overflow in factorial calculation if len >= 21
long long unsigned int	facto(int n)
{
	uint_ll	res = 1;
	uint_ll	oldres = 1;

	while (n > 1)
	{
		oldres = res;
		res *= n--;
		if (oldres > res)
			return (fprintf(stderr, "%s\n", OVFLW_FACTO), 0);
	}
	return (res);
}

/*	sum up factoriel of all the doublons to reduce the number of anagrams	*/
long long unsigned int	repeted_letters_reduction(char *s)
{
	const int	len = strlen(s);
	uint_ll		res = 1;
	uint_ll		nb;
	int			i = -1;
	int			j;

	while (++i < len)
	{
		nb = 1;
		j = i;
		while (++j < len)
			if (s[j] && s[i] == s[j])
			{
				nb++;
				s[j] = '\0';
			}
		res *= facto(nb);
	}
	free(s);
	return (res);
}

bool	input_prep(int argc, char **argv, uint_ll *len, uint_ll *net_words_nb)
{
	if (argc != 2 || !argv || !**argv)
		return(fprintf(stderr, "%s\n", BADARG), false);
	
	*len = strlen(*argv);
	const uint_ll	raw_words_nb = facto(*len);
	const uint_ll	repet = repeted_letters_reduction(strdup(*argv));
	*net_words_nb = raw_words_nb / repet;

	for (unsigned long long int i = 0; i < *len ; ++i)
		(*argv)[i] = tolower((*argv)[i]);

	printf("Input\t\t: %s\nLength\t\t: %llu\nRaw words nb\t: ", *argv, *len);
	if (!raw_words_nb)
		printf("overflow detected in calculation\n");
	else
	{
		printf("%llu\nNet words nb\t: %llu\n", raw_words_nb, *net_words_nb);
		//printf("(raw_words:%llu / repet:%llu)\n", raw_words_nb, repet);
	}
	return (true);
}
