#include "get_next_line.h"
#include <fcntl.h>

int main(void)
{
	int op;
	char *str;
	int	status = 1;
	
	if((op = open("file", O_RDONLY)) == -1)
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
		//write(1, "main : ", 7);
		//write(1, str, strlen(str));
		//write(1, "\n", 1);
	} while(status > 0);
	
}
