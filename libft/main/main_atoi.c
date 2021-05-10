#include "../libft.h"

#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int main(int argc, char* argv[])
{
	printf("str = %s\n", argv[1]);
	printf("n1 = %d\nn2 = %d\n", atoi(argv[argc - 1]), ft_atoi(argv[argc - 1]));
}
