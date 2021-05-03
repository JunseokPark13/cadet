#include "../libft.h"

#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char k1[] = "1234512345";
	char k2[] = "1134512345";
	int k3[] = {50, 51, 52, 53, 54, 55};

	write(1, memchr(k1, '2', 5), 7);
	write(1, "\n", 1);
	write(1, ft_memchr(k1, '2', 5), 7);
	write(1, "\n", 1);
	
	write(1, memchr(k2, '2', 5), 7);
	write(1, "\n", 1);
	write(1, ft_memchr(k2, '2', 5), 7);
	write(1, "\n", 1);

	write(1, memchr(k3, 53, 10), 7);
	write(1, "\n", 1);
	write(1, ft_memchr(k3, 53, 10), 7);
	write(1, "\n", 1);

}
