#include "../libft.h"

#include <stdio.h>

char	upper_odd(unsigned int i, char c)
{
	char tmp;

	if (i % 2 == 1 && (97 <= c && c <= 122))
		tmp = c - 32;
	else
		tmp = c;
		
	return (tmp);
}


int main(void)
{
	char *s1 = "abcdefgh";
	char *res1 = ft_strmapi(s1, upper_odd);

	printf("%s\n%s\n", s1, res1);
}
