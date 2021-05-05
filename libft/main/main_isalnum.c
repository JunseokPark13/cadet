#include "../libft.h"

#include <ctype.h>
#include <stdio.h>

int main(void)
{
	char k = 'a';
	for(int i = 0; i < 26; i++)
		printf("%c -> %d %d\n", k + i, isalnum(k + i), ft_isalnum(k + i));
	k = '0';
	for(int i = 0; i < 10; i++)
		printf("%c -> %d %d\n", k + i, isalnum(k + i), ft_isalnum(k + i));
	printf("%c -> %d %d\n", '\0', isalnum('\0'), ft_isalnum('\0'));
	printf("%c -> %d %d\n", '\t', isalnum('\t'), ft_isalnum('\t'));
	printf("%c -> %d %d\n", '\n', isalnum('\n'), ft_isalnum('\n'));
	printf("%c -> %d %d\n", '!', isalnum('!'), ft_isalnum('!'));
	printf("%c -> %d %d\n", '(', isalnum('('), ft_isalnum('('));
	printf("%c -> %d %d\n", '+', isalnum('+'), ft_isalnum('+'));
}
