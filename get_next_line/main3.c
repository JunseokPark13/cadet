#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int op, op2;
	char *str, *str2;
	int	status = 1;
	
	if((op = open("A", O_RDONLY)) == -1)
	{
		printf("can't open file\n");
		exit(0);
	}
	if((op2 = open("B", O_RDONLY)) == -1)
	{
		printf("can't open file\n");
		exit(0);
	}

	printf("OPEN_MAX : %d\n", OPEN_MAX);
	printf("BUFFER_SIZE : %d\n", BUFFER_SIZE);
	printf("op : %d\n", op);
	printf("op2 : %d\n", op2);

	do {
		status = get_next_line(op, &str);
		printf("%d : %s\n", status, str);
		status = get_next_line(op2, &str2);
		printf("%d : %s\n", status, str2);
	} while(status > 0);
	
}
