#include "../libft.h"

#include <ctype.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	printf("c = %c\n", argv[argc - 1][0]);
	printf("n1 = %c\n", toupper(argv[argc - 1][0]));
	printf("n2 = %c\n", ft_toupper(argv[argc - 1][0]));
}
