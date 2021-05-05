#include "../libft.h"

#include <ctype.h>
#include <stdio.h>

int main(void)
{
	char k = '0';
	printf("%c -> %d %d\n", 'a', isdigit('a'), ft_isdigit('a'));
	printf("%c -> %d %d\n", 'k', isdigit('k'), ft_isdigit('k'));
	printf("%c -> %d %d\n", 'z', isdigit('z'), ft_isdigit('z'));
	for(int i = 0; i < 10; i++)
		printf("%c -> %d %d\n", k + i, isdigit(k + i), ft_isdigit(k + i));
	printf("%c -> %d %d\n", '\0', isdigit('\0'), ft_isdigit('\0'));
	printf("%c -> %d %d\n", '\t', isdigit('\t'), ft_isdigit('\t'));
	printf("%c -> %d %d\n", '\n', isdigit('\n'), ft_isdigit('\n'));
	printf("%c -> %d %d\n", '!', isdigit('!'), ft_isdigit('!'));
	printf("%c -> %d %d\n", '(', isdigit('('), ft_isdigit('('));
	printf("%c -> %d %d\n", '+', isdigit('+'), ft_isdigit('+'));
}
