#include "get_next_line.h"

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
		*reminder = ft_strdup(ptr_n + 1);
		*ptr_n = '\n';
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

int	ft_return(int readed, char **line, char **reminder)
{
	if (readed > 0)
		return 1;
	if (readed == 0 && *reminder)
	{
		*line = ft_strdup(*reminder);
		free(*reminder);
		*reminder = 0x000;
		return readed;
	}
	if (readed == 0 && !*reminder)
		*line = ft_strdup("");
	return readed;
}


void	ft_bzero(void *s, size_t n) {
	size_t	i;
	char	*dst;

	dst = (char *)s;
	i = 0;
	while (i < n) {
		dst[i] = '\0';
		++i;
	}
}

int	get_next_line(int fd, char **line)
{
	char static	*reminder;
	char		buf[BUFFER_SIZE + 1];
	int		readed;
	char		*ptr_n;

	ptr_n = 0x000;
	readed = 1;
	ft_bzero(buf, BUFFER_SIZE + 1);
	if (!line || fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	if (reminder && (ptr_n = ft_strchr(reminder, '\n')))
	{
		*line = set_line(&reminder, ptr_n);
		return (ft_return(readed, line, &reminder));
	}
	while (!ptr_n && (readed = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[readed] = '\0';
		if ((ptr_n = set_reminder(&reminder, buf)))
			*line = set_line(&reminder, ptr_n);
	}
	return (ft_return(readed, line, &reminder));
}
