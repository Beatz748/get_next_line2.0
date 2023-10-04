#include "get_next_line.h"

int	main()
{
	int	fd;
	char	*line = 0x000;

	fd = open("example", O_RDONLY);


	while (get_next_line(fd, &line))
	{
      		printf("%s\n", line);
      		free(line);
	}
}
