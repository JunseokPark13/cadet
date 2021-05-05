#include "../libft.h"

#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char *s1 = "12345";
	char *s2 = "abcdef";
	char *join1 = ft_strjoin(s1, s2);

	char *s3 = "";
	char *s4 = "kk";
	char *join2 = ft_strjoin(s3, s4);

	write(1, join1, strlen(join1));
	write(1, "\n", 1);
	write(1, join2, strlen(join2));
	write(1, "\n", 1);
}
