#include "../libft.h"

#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char k[] = "123abc456abdc";
	char c[] = "abc";

	write(1, ft_strnstr(k, c, 13), 13);
	write(1, "\n", 1);
}
