#include "../../libft.h"

#include <ctype.h>
#include <stdio.h>

int main(void)
{
	char k = 0;
	for(int i = 0; i < 128; i++)
		printf("%c -> %c %c\n", k + i, toupper(k + i), ft_toupper(k + i));
}
