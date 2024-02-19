#include "../inc/main.h"

//	overflow in factorial calculation if len >= 21
long long unsigned int	facto(int n)
{
	long long unsigned int	res = 1;
	long long unsigned int	oldres = 1;

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
	const int				len = strlen(s);
	long long unsigned int	res = 1;
	long long unsigned int	nb;
	int						i = -1;
	int						j;

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

bool	input_prep(int argc, char **argv, unsigned long long int *len, unsigned long long int *net_words_nb)
{
	if (argc != 2 || !argv || !**argv)
		return(fprintf(stderr, "%s\n", BADARG), false);
	
	*len = strlen(*argv);
	const unsigned long long int	raw_words_nb = facto(*len);
	const unsigned long long int	repet = repeted_letters_reduction(strdup(*argv));
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

int	get_a_file_fd(void)
{
	char		*filename = "tmp.txt";
	const int	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	int			fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, mode);

	if (fd < 0)
		fprintf(stderr, "%s%s\n", FILE_PB, filename);
	return (fd);
}
