#include "../libft.h"

#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	char **ary;

	char *s = argv[1];
	char c = argv[argc - 1][0];

	ary = ft_split(s, c);

	int cnt = 0;
	while (ary[cnt])
		cnt++;

	for(int i = 0; i < cnt; i++){
		write(1, ary[i], strlen(ary[i]));
		write(1, "\n", 1);
	}

}
