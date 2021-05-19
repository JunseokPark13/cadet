#include "ft_printf.h"

void	test(unsigned int num)
{
	printf("%d\n", (unsigned int)num);
}


int main(void)
{
	char *str = "01234567890";
	int origin = printf("printf    : ABCDE%-10.*dPPPPP%15.5sKKKKK\n", 3, 123, str);
	int ft =  ft_printf("ft_printf : ABCDE%-10.*dPPPPP%15.5sKKKKK\n", 3, 123, str);


	printf("origin = %d\nft = %d\n", origin, ft);
	return (0);
}
