#include "../libft.h"

#include <ctype.h>
#include <stdio.h>

int main(void)
{
	char k = 0;
	for(int i = 0; i < 128; i++)
		printf("%c -> %d %d\n", k + i, isprint(k + i), ft_isprint(k + i));
}
