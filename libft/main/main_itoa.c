#include "../libft.h"

#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int main(int argc, char *argv[])
{
	int a = atoi(argv[argc - 1]);
	char *nstr = ft_itoa(a);

	write(1, nstr, strlen(nstr));
	write(1, "\n", 1);
}
