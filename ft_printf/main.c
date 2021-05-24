#include "ft_printf.h"

void	test(unsigned int num)
{
	printf("%d\n", (unsigned int)num);
}

#include <limits.h>

int main(void)
{
	
//	char *str = "0123456789";
//	int origin = printf("printf    : [%s]\n", 123);
	int ft =  ft_printf("ft_printf : [%s]\n", 123);
//				 printf("printf    : ABCDE%0*.*dKKKKK\n", 1, 0, 0);
//			  ft_printf("ft_printf : ABCDE%0*.*dKKKKK\n", 1, 0, 0);

//	printf("origin = %d\nft = %d\n", origin, ft);
//	while(1);
	return (0);
}
