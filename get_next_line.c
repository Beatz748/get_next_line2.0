#include "get_next_line.h"

int	ft_reminder(char **reminder, char **line)
{

}

char	*set_reminder(char **reminder, char *buf)
{
	char	*tmp;

	if (!*reminder || (*reminder && !*reminder[0]))
		*reminder = ft_strdup(buf);
	else
	{
		tmp = *reminder;
		*reminder = ft_strjoin(*reminder, buf);
		free(tmp);
	}
	return (ft_strchr(*reminder, '\n'));
}

char	*set_line(char **reminder, char *ptr_n)
{
	char	*result;
	char	*tmp;

	*ptr_n = 0;
	tmp = *reminder;
	result = ft_strdup(*reminder); 
	if (*(ptr_n + 1))
	{
		*reminder = (ptr_n + 1);
		free(tmp);
	}
	else
	{
		*ptr_n = '\n';
		free(*reminder);
		*reminder = 0x000;
	}
	return (result);

}

int	get_next_line(int fd, char **line)
{
	char static	*reminder;
	char		buf[BUFFER_SIZE + 1];
	int		readed;
	char		*ptr_n;

	ptr_n = 0x000;
	if (!line || fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	while (!ptr_n && (readed = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[readed] = 0;
		if ((ptr_n = set_reminder(&reminder, buf)))
		{
			*line = set_line(&reminder, ptr_n);
		}

	}
	if (readed > 0)
		return 1;
	return 0;
}