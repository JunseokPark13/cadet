#include "ft_printf.h"
#include <stdio.h>
void	test(unsigned int num)
{
	printf("%d\n", (unsigned int)num);
}

#include <limits.h>

int main(void)
{
	
//	char *str = "0123456789";
//	char *p = NULL;
	int origin = printf("printf    : [%-20.3d]\n", INT_MIN);
	int ft =  ft_printf("ft_printf : [%-20.3d]\n", INT_MIN);
//				 printf("printf    : ABCDE%-12.5rKKKKK\n");
//			  ft_printf("ft_printf : ABCDE%-12.5rKKKKK\n");

	printf("origin = %d\nft = %d\n", origin, ft);
	//system("Leaks test");
	return (0);
}
