#include "../libft.h"

#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char *s1 = "12345";
	char *s1_1 = strdup(s1);
	char *s1_2 = ft_strdup(s1);

	char *s2 = "123\045";
	char *s2_1 = strdup(s2);
	char *s2_2 = ft_strdup(s2);

	char *s3 = "";
	char *s3_1 = strdup(s3);
	char *s3_2 = ft_strdup(s3);
	
	write(1, s1_1, sizeof(s1));
	write(1, "\n", 1);
	write(1, s1_2, sizeof(s1));
	write(1, "\n", 1);
	
	write(1, s2_1, sizeof(s2));
	write(1, "\n", 1);
	write(1, s2_2, sizeof(s2));
	write(1, "\n", 1);

	write(1, s3_1, sizeof(s3));
	write(1, "\n", 1);
	write(1, s3_2, sizeof(s3));
	write(1, "\n", 1);

}
