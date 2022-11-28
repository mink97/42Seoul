#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	char *line;

	int fd = open("./test.txt", O_RDONLY);
	while((line = get_next_line(fd)) > 0)
	{
		printf("line : %s\n",line);
		free(line);
	}
	printf("line : %s\n",line);
	free(line);
	return (0);
}
