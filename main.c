#include "main.h"

char *join(const char* s, const char* s2)
{
	char *result = malloc(strlen(s) + strlen(s2) + 1);

	if (result)
	{
		strcpy(result, s1);
		strcat(result, s2);
	}
	return result;
}

int	get_a_file_fd(const char *s, int len)
{
	const char	*ext = "_anag.txt";
	char		*filename = join(s, ext);
	int			fd = open(filename, O_RDWR | O_CREAT | O_TRUNC);

	if (fd < 0)
		fprintf(stderr, "%s%s\n", FILE_PB, filename);
	free(filename);
	return (fd);
}

int	main(int argc, char ** argv, __attribute__((unused))char ** envp)
{
	unsigned long long int	len;
	int						fd;

	if (!input_prep(argc, ++argv, &len))
		return (2);

	fd = get_a_file_fd(*argv, len);
	if (fd < 0)
		return (3);
	// writing in a file not finished + deal with french dico
	// + get rid of doublon (sort + uniq via execve?)
	// accents de french dico
	gen_word(*argv, 0, len - 1);
}

