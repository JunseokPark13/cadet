#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "../libft.h"

int main(void)
{
	printf("%d\n", atoi("9223372036854775807"));
	printf("%d\n", atoi("-9223372036854775809"));

}

