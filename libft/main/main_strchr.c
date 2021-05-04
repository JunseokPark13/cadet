#include "../libft.h"

#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char s1[] = "abcdabcd";
	char s2[] = "abcdffgh";
	
	write(1, strchr(s1, 'c'), 8);
	write(1, "\n", 1);
	write(1, ft_strchr(s1, 'c'), 8);
	write(1, "\n", 1);
	
	write(1, "\n", 1);
	
	write(1, "\n", 1);
	write(1, strchr(s2, 'e'), 8);
	write(1, "\n", 1);
	write(1, ft_strchr(s2, 'e'), 8);
	write(1, "\n", 1);

	char k = 0;
	write(1, "\n", 1);
	write(1, strchr(s1, k), 8);
	write(1, "\n", 1);
	write(1, ft_strchr(s1, k), 8);
	write(1, "\n", 1);
	write(1, "\n", 1);
}
