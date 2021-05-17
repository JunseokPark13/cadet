#include "ft_printf.h"

int main(void)
{

	printf("printf    : ABCDE%8.*iPPPPP\n",4,-300);
	ft_printf("ft_printf : ABCDE%8.*iPPPPP\n",4,-300);
	
	return (0);
}
