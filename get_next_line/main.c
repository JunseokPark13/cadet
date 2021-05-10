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
	
	printf("OPEN_MAX : %d\n", OPEN_MAX);
	printf("BUFFER_SIZE : %d\n", BUFFER_SIZE);
	
	//printf("wrong op : %d\n\n", get_next_line(15, &str));

	do {
		status = get_next_line(op, &str);
		//if (status == 0)
		//	break;
		printf("%d : %s\n", status, str);
	} while(status > 0);
	
}
