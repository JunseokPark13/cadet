#include "get_next_line.h"
#include <fcntl.h>

int main(void)
{
	int op;
	char *str;
	int	status = 1;
	
	if((op = open("test.c", O_RDONLY)) == -1)
	{
		printf("can't open file\n");
		exit(0);
	}
	
	printf("BUFFER_SIZE : %d\n", BUFFER_SIZE);

	do {
		status = get_next_line(op, &str);
		printf("%d : %s\n", status, str);
	} while(status > 0);
}
