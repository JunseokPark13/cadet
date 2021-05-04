#include "../libft.h"

#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char s1[] = "123456";
	char s2[] = "123456";
	char s3[] = "123496";
	char s4[] = "";

	printf("%s, %s : %d\n", s1, s2, strncmp(s1, s2, 7));
	printf("%s, %s : %d\n", s1, s2, ft_strncmp(s1, s2, 7));
	
	printf("%s, %s : %d\n", s1, s3, strncmp(s1, s3, 7));
	printf("%s, %s : %d\n", s1, s3, ft_strncmp(s1, s3, 7));
	
	printf("%s, %s : %d\n", s1, s3, strncmp(s1, s3, 4));
	printf("%s, %s : %d\n", s1, s3, ft_strncmp(s1, s3, 4));
	
	printf("%s, %s : %d\n", s1, s4, strncmp(s1, s4, 7));
	printf("%s, %s : %d\n", s1, s4, ft_strncmp(s1, s4, 7));
	
	printf("%s, %s : %d\n", s4, s1, strncmp(s4, s1, 7));
	printf("%s, %s : %d\n", s4, s1, ft_strncmp(s4, s1, 7));
	

	printf("%s, %s : %d\n", "test\200", "test\0", strncmp("test\200", "test\0", 6));
	printf("%s, %s : %d\n", "test\200", "test\0", ft_strncmp("test\200", "test\0", 6));
}
