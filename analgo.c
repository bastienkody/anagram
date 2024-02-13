#include "main.h"

void	swap(char *a, char *b)
{
	char	tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}

void	gen_word(char *s, int start, int end)
{
	if (start == end)
		printf("%s\n", s);
	else 
	{
		for (int i = start; i <= end; i++) 
		{
			swap(s + start, s + i);
			gen_word(s, start + 1, end);
			swap(s + start, s + i);
		}
	}
}