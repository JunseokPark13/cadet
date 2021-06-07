#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	char	*cmd;
	char	tmp;
	int		cur;

	
	cmd = (char*)malloc(sizeof(char) * 4);
	cur = 0;
 	if (argc == 1)
	{
		while ((read(0, &tmp, 1)))
		{
			cmd[cur++] = tmp;
			if (tmp == '\0')
				break;
			else if (tmp == '\n')
			{
				printf("cmd : %s", cmd);
				cur = 0;
			}
		}
	}
}
