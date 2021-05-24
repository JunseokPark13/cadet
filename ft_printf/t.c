#include <stdio.h>
#include "ft_printf.h"

char	*a(void)
{
	return ((char*)(-1));
}

int main(void)
{
	char *str = a();
	char *k;

	k = ft_strdup("AAA");
	printf("1 : %s\n", k);

	str = join_strs(str, k);

	printf("2 : %d\n", str);
}
