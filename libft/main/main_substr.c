#include "../libft.h"

#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	char *k;
	char *s = argv[1];
	int start = atoi(argv[2]);
	int len = atoi(argv[argc - 1]);

	k = ft_substr(s, start, len);
	
	write(1, k, strlen(k));
	write(1, "\n", 1);
}
