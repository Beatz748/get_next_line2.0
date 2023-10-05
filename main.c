#include "get_next_line.h"

int	main()
{
	int	fd;
	char	*line = 0x000;

//	fd = o/pen("long_line.txt", O_RDONLY);
	fd = open("example", O_RDONLY);


	while (get_next_line(fd, &line))
	{

      		printf("%s\n", line);
      		free(line);
	}
}
