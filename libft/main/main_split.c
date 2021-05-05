#include "../libft.h"

#include <stdio.h>
#include <unistd.h>

int main(void)
{
	//char k[] = "aaaa123aaaaaaaaaaaa456a789a";
	//char k2[] = "lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse";
	//char set = 'a';

	//char **str = ft_split(k, set);
	char **str2 = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'i');
	//char **str2 = ft_split("   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ');
	printf("----main----\n");
	//for(int i = 0; i < 4; i++)
		//printf("%s\n", str[i]);

	
		write(1, str2[11], strlen(str2[11]));
		write(1, "\n", 1);
		//write(1, str2[12], strlen(str2[12]));
		//write(1, "\n", 1);
	for(int i = 0; i < 13; i++)
	{
		//printf("%s\n", str2[i]);
	//	write(1, str2[i], strlen(str2[i]));
	//	write(1, "\n", 1);
	}

	
}
