#include "../libft.h"

#include <unistd.h>

int main(void)
{
	char s1[] = "123456789";
	char s2[] = "123456789";
	char s3[] = "123456789";

	memmove(s1 + 1, s1, 5);
	ft_memmove(s2 + 1, s2, 5);
	ft_memcpy(s3 + 1, s3, 5);

	write(1, s1, strlen(s1));
	write(1, "\n", 1);
	write(1, s2, strlen(s2));
	write(1, "\n", 1);
	write(1, s3, strlen(s3));
	write(1, "\n", 1);
}
