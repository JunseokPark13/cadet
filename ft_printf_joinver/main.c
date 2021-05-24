#include "ft_printf.h"

void	test(unsigned int num)
{
	printf("%d\n", (unsigned int)num);
}

#include <limits.h>

int main(void)
{
	//char *str = "012345";
	int origin = printf("printf    : %c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c\n", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0);
	int ft =  ft_printf("ft_printf : %c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c\n", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0);
  	   
//	   printf("printf    : %s\n", 123);
	ft_printf("ft_printf : %s\n", 123);

	printf("origin = %d\nft = %d\n", origin, ft);
//	while(1);
	return (0);
}
