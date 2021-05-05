#include "../libft.h"

#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char *s1 = "123456789";
	char *sub1_1 = ft_substr(s1, 0, 5);
	char *sub1_2 = ft_substr(s1, 5, 5);

	write(1, sub1_1, 5);
	write(1, "\n", 1);
	write(1, sub1_2, 5);
	write(1, "\n", 1);
}
