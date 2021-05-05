#include "../libft.h"


#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char *s1 = "abc123abc";
	char *set = "abc";

	char *res = ft_strtrim(s1, set);

	write(1, res, strlen(res));
	write(1, "\n", 1);

	s1 = "acbc123bbac";

	char *res2 = ft_strtrim(s1, set);
	write(1, res2, strlen(res2));
	write(1, "\n", 1);

	s1 = "acbc1ab2cbca3bbac";

	char *res3 = ft_strtrim(s1, set);
	write(1, res3, strlen(res3));
	write(1, "\n", 1);

}
