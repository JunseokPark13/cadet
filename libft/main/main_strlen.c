#include "../libft.h"

#include <stdio.h>

int main(void)
{
	char k[] = "12345";
	char *k2 = "1234567890";
	char k3[7] = "123456";

	printf("%s -> %ld, %ld\n", k, strlen(k), ft_strlen(k));
	printf("%s -> %ld, %ld\n", k2, strlen(k2), ft_strlen(k2));
	printf("%s -> %ld, %ld\n", k3, strlen(k3), ft_strlen(k3));
}
