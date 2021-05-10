#include "../libft.h"

#include <ctype.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	printf("c = %c\n", argv[argc - 1][0]);
	printf("n1 = %d\n", isprint(argv[argc - 1][0]));
	printf("n2 = %d\n", ft_isprint(argv[argc - 1][0]));
}
