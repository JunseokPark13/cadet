#include "../libft.h"

#include <unistd.h>
#include <stdio.h>

int main(void)
{
	char *k = calloc(10, sizeof(char));
	char *k2 = ft_calloc(10, sizeof(char));

	k[9] = 'A';
	k2[9] = 'A';
	write(1, k, 10);
	write(1, "\n", 1);
	write(1, k2, 10);
	free(k);
	free(k2);
}
