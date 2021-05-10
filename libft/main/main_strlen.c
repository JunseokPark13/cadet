#include "../libft.h"

#include <stdio.h>

int main(int argc, char* argv[])
{
	char *s1, *s2;
	
	s1 = (char*)malloc(sizeof(char) * atoi(argv[2]));
	s2 = (char*)malloc(sizeof(char) * atoi(argv[2]));
	
	for(int i = 0; i < (int)strlen(argv[1]); i++){
		s1[i] = argv[1][i];
		s2[i] = argv[1][i];
	}

	printf("argc = %d\n", argc);
	printf("s = %s\n", s1);

	int n1 = strlen(s1);
	int n2 = strlen(s2);

	printf("n1 = %d\nn2 = %d\n", n1, n2);
}
