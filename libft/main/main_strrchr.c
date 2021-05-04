#include "../libft.h"

#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char s3[] = "abcdeakkkk";

	write(1, strchr(s3, 'a'), 8);
	write(1, "\n", 1);
	write(1, ft_strchr(s3, 'a'), 8);
	write(1, "\n", 1);
	
	write(1, "\n", 1);
	
	write(1, "\n", 1);
	write(1, strrchr(s3, 'a'), 8);
	write(1, "\n", 1);
	write(1, ft_strrchr(s3, 'a'), 8);
	write(1, "\n", 1);

	char k = 0;
	write(1, "\n", 1);
	write(1, strrchr(s3, k), 8);
	write(1, "\n", 1);
	write(1, ft_strrchr(s3, k), 8);
	write(1, "\n", 1);
	write(1, "\n", 1);
}
