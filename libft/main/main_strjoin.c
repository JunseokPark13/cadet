#include "../libft.h"

#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	char *str;
	
	char *s1 = argv[1];
	char *s2 = argv[argc - 1];
	
	str = ft_strjoin(s1, s2);
	write(1, str, strlen(str));
	write(1, "\n", 1);
}
