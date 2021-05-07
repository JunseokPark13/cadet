#include "../libft.h"

#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int main(void)
{
	char n1[] = "2147483647";
	char n2[] = "-2147483648";
	char n3[] = "123abcdef567";
	char n4[] = "-123abcdef567";
	char n5[] = "+123abcdef567";
	char n6[] = "--123abcdef567";
	char n7[] = "-+-++123abcdef567";
	char n8[] = "abcd123";
	char n9[] = "-";

	printf("%s => %d\n", n1, atoi(n1));
	printf("%s => %d\n\n", n1, ft_atoi(n1));
	
	printf("%s => %d\n", n2, atoi(n2));
	printf("%s => %d\n\n", n2, ft_atoi(n2));
	
	printf("%s => %d\n", n3, atoi(n3));
	printf("%s => %d\n\n", n3, ft_atoi(n3));
	
	printf("%s => %d\n", n4, atoi(n4));
	printf("%s => %d\n\n", n4, ft_atoi(n4));
	
	printf("%s => %d\n", n5, atoi(n5));
	printf("%s => %d\n\n", n5, ft_atoi(n5));
	
	printf("%s => %d\n", n6, atoi(n6));
	printf("%s => %d\n\n", n6, ft_atoi(n6));
	
	printf("%s => %d\n", n7, atoi(n7));
	printf("%s => %d\n\n", n7, ft_atoi(n7));

	printf("%s => %d\n", n8, atoi(n8));
	printf("%s => %d\n\n", n8, ft_atoi(n8));
	
	printf("%s => %d\n", n9, atoi(n9));
	printf("%s => %d\n\n", n7, ft_atoi(n9));

	printf("%s => %d\n", "\n\n\n\t1234567", atoi("\n\n\n\t1234567"));
	printf("%s => %d\n\n", "\n\n\n\t1234567", ft_atoi("\n\n\n\t1234567"));
	

	printf("%s => %d\n", "", atoi(""));
	printf("%s => %d\n", "", ft_atoi(""));
}
