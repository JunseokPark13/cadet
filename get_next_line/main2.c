#include "get_next_line.h"
#include <fcntl.h>

int main(void)
{
	int op;
	//char *str;
	//int	status = 1;

	/*
	if((op = open("file", O_RDONLY)) == -1)
	{
		printf("can't open file\n");
		exit(0);
	}
	*/
	op = 0;
	printf("OPEN_MAX : %d\n", OPEN_MAX);
	printf("BUFFER_SIZE : %d\n", BUFFER_SIZE);
	printf("op : %d\n", op);

	char s[BUFFER_SIZE + 1];
	read(op, s, BUFFER_SIZE);
	printf("read : %s\n", s); 

	/*
	do {
		status = get_next_line(op, &str);
		printf("%d : %s\n", status, str);
	} while(status > 0);
	*/
}
