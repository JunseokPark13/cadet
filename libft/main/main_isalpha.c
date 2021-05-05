#include "../libft.h"

#include <ctype.h>
#include <stdio.h>

int main(void)
{
	char k = 'a';
	for(int i = 0; i < 26; i++)
		printf("%c -> %d %d\n", k + i, isalpha(k + i), ft_isalpha(k + i));
	printf("%c -> %d %d\n", '6', isalpha('6'), ft_isalpha('6'));
	printf("%c -> %d %d\n", '\0', isalpha('\0'), ft_isalpha('\0'));
	printf("%c -> %d %d\n", '\t', isalpha('\t'), ft_isalpha('\t'));
	printf("%c -> %d %d\n", '\n', isalpha('\n'), ft_isalpha('\n'));
	printf("%c -> %d %d\n", '!', isalpha('!'), ft_isalpha('!'));
	printf("%c -> %d %d\n", '(', isalpha('('), ft_isalpha('('));
	printf("%c -> %d %d\n", '+', isalpha('+'), ft_isalpha('+'));
}
