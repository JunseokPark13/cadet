#include "get_next_line.h"

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	char *str;

	str = (char*)malloc(sizeof(char*) * (BUFFER_SIZE + 1));

	int status;
	
	do {
		status = get_next_line(0, &str);
		printf("%d : %s\n",status, str);
	}while (status > 0);
}
