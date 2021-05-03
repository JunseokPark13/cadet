#include "../libft.h"

#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char s1[] = "012345";
	char s2[] = "012345";
	char s3[] = "012399";
	char s4[] = "";
	char s5[] = "";

	printf("%s %s %d : %d\n", s1, s2, 6, memcmp(s1, s2, 6 * sizeof(char)));
	printf("%s %s %d : %d\n\n", s1, s2, 6, ft_memcmp(s1, s2, 6 * sizeof(char)));
	
	printf("%s %s %d : %d\n", s1, s3, 4, memcmp(s1, s3, 4 * sizeof(char)));
	printf("%s %s %d : %d\n\n", s1, s3, 4, ft_memcmp(s1, s3, 4 * sizeof(char)));
	
	printf("%s %s %d : %d\n", s1, s3, 6, memcmp(s1, s3, 6 * sizeof(char)));
	printf("%s %s %d : %d\n\n", s1, s3, 6, ft_memcmp(s1, s3, 6 * sizeof(char)));
	
	printf("%s %s %d : %d\n", s1, s4, 0, memcmp(s1, s4, 0 * sizeof(char)));
	printf("%s %s %d : %d\n\n", s1, s4, 0, ft_memcmp(s1, s4, 0 * sizeof(char)));
	
	printf("%s %s %d : %d\n", s4, s5, 2, memcmp(s4, s5, 2 * sizeof(char)));
	printf("%s %s %d : %d\n\n", s4, s5, 2, ft_memcmp(s4, s5, 2 * sizeof(char)));

}
