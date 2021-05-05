#include "../libft.h"

#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int main(void)
{
	int max = INT_MAX;
	int min = INT_MIN;
	int n1 = -1234567;
	int n2 = -12345;
	int n3 = 0;
	int n4 = 12345;
	int n5 = 1234567;

	printf("%s\n", ft_itoa(max));
	printf("%s\n", ft_itoa(min));
	printf("%s\n", ft_itoa(n1));
	printf("%s\n", ft_itoa(n2));
	printf("%s\n", ft_itoa(n3));
	printf("%s\n", ft_itoa(n4));
	printf("%s\n", ft_itoa(n5));
}
