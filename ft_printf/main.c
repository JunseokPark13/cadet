#include "ft_printf.h"

void	test(unsigned int num)
{
	printf("%d\n", (unsigned int)num);
}


int main(void)
{
	char *str = "12345";
	int origin = printf("printf    : ABCDE%15pPPPPP\n", str);
	int ft =  ft_printf("ft_printf : ABCDE%15pPPPPP\n", str);


	printf("origin = %d\nft = %d\n", origin, ft);
	return (0);
}
