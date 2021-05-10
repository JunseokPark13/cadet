#include "../libft.h"

#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	char *k, *k2;
	int cnt = atoi(argv[argc - 2]);
	int size = atoi(argv[argc - 1]);
	k = calloc(cnt, size);
	k2 = ft_calloc(cnt, size);

	write(1, k, cnt * size);
	write(1, "\n", 1);
	write(1, k2, cnt * size);
	write(1, "\n", 1);

	free(k);
	free(k2);
}
