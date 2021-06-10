#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int op;
	char *str;
	int	status = 1;
	
	if((op = open("A", O_RDONLY)) == -1)
	{
		printf("can't open file\n");
		exit(0);
	}
	
	printf("OPEN_MAX : %d\n", OPEN_MAX);
	printf("BUFFER_SIZE : %d\n", BUFFER_SIZE);
	printf("op : %d\n", op);

	do {
		status = get_next_line(op, &str);
		printf("%d : %s\n", status, str);
		free(str);
	} while(status > 0);
	system("leaks test");
	
}
