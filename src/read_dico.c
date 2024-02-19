#include "../inc/main.h"

void	free_dico(char **dico)
{
	int	i = -1;

	if (!dico && printf("nothing to free in dico!!\n"))
		return ;

	while (dico[++i])
		free(dico[i]);
	free(dico);
}

void	print_dico(char **dico)
{
	int	i = -1;

	if (!dico)
		return ;

	while (dico[++i])
		printf("%s\n", dico[i]);
}

bool	search_in_dico(char **dico, char *entry)
{
	int	i = -1;

	if (!dico || !entry || !*entry)
		return (fprintf(stderr, "Bad input in search_in_dico\n"), false);

	while (dico[++i])
		if (!strcmp(entry, dico[i]))
			return (true);
	
	return (false);
}

char	**get_a_dico(void)
{
	const int	fd = open(DICO_PATH, O_RDONLY);
	const int	size = 336530;
	int			i = -1;
	char		**dico;
	char		*entry = NULL;

	if (fd < 0)
		return (fprintf(stderr, "Can't open dico (fd=%i)\n", fd), NULL);
	
	if (!(dico = malloc((size + 1) * sizeof(char *))))
		return (fprintf(stderr, "Malloc for dico failed\n"), NULL);

	while ((entry = get_next_line(fd)) != NULL)
	{
		if (!entry)
			break ;
		if (strchr(entry, '\n'))
			entry[strlen(entry) - 1] = '\0';
		dico[++i] = entry;
	}
	dico [++i] = NULL;
	return (dico);
}
