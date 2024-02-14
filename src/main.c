#include "../inc/main.h"

/*	anagramme algo	*/
void	swap(char *a, char *b)
{
	char	tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}

void	gen_word(char *s, int start, int end, int fd)
{

	if (start == end)
	{
		write(fd, s, strlen(s));
		write(fd, "\n", 1);
	}
	else 
	{
		for (int i = start; i <= end; i++) 
		{
			swap(s + start, s + i);
			gen_word(s, start + 1, end, fd);
			swap(s + start, s + i);
		}
	}
}

int	main(int argc, char ** argv, __attribute__((unused))char ** envp)
{
	unsigned long long int	len;
	unsigned long long int	net_words_nb;
	int						fd;

	if (!input_prep(argc, ++argv, &len, &net_words_nb))
		return (2);

	fd = get_a_file_fd();
	if (fd < 0)
		return (3);

	gen_word(*argv, 0, len - 1, fd);

	close(fd);
}

