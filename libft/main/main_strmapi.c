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


int main(int argc, char* argv[])
{
	char *res1 = ft_strmapi(argv[argc - 1], upper_odd);

	printf("%s\n%s\n", argv[argc - 1], res1);
}
