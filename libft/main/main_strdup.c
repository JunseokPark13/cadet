#include "../libft.h"

#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	char *k, *k2;

	k = strdup(argv[argc - 1]);
	k2 = ft_strdup(argv[argc - 1]);

	write(1, k, strlen(argv[argc - 1]));
	write(1, "\n", 1);
	write(1, k2, strlen(argv[argc - 1]));
	write(1, "\n", 1);
}
