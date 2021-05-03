#include "../libft.h"

#include <stdio.h>
#include <unistd.h>

int main(void){
	char k1[10] = "1234";
	char k2[10] = "aaaa";
	
	char k3[10] = "1234";
	char k4[10] = "bbbb";

	//char empty[5] = "";

	int n1 = strlcat(k2, k1, 0);
	int n2 = ft_strlcat(k4, k3, 0);

	write(1, k2, sizeof(k2));
	write(1, "\n", 1);
	write(1, k2, sizeof(k2));
	write(1, "\n", 1);

	printf("n1 = %d\n", n1);
	printf("n2 = %d", n2);
}
