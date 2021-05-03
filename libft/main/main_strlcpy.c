#include "../libft.h"

#include <unistd.h>
#include <stdio.h>

int main(void){
	char k1[10] = "123456789";
	char k2[10] = "99999";
	char k3[10] = "54321";
	char k4[10] = "777";
	char k5[10] = "555";

	size_t len = ft_strlcpy(k2, k1, 5);
	size_t len2 = ft_strlcpy(k4, k3, 1);
	size_t len3 = ft_strlcpy(k5, "", 0);
	
	write(1, k2, 10);
	write(1, "\n", 1);
	printf("%ld\n\n", len);

	write(1, k4, 10);
	write(1, "\n", 1);
	printf("%ld\n\n", len2);

	write(1, k5, 10);
	write(1, "\n", 1);
	printf("%ld\n", len3);
	
}
