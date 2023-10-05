#include "get_next_line.h"

void	*ft_memcpy(void *destination, const void  *source, size_t n) {
	size_t	i;
	char	*dst;
	char	*src;

	i = 0;
	src = (char *)source;
	dst = destination;

	if (!src && !dst)
		return (0x000);
	while (i < n) {
		dst[i] = src[i];
		++i;
	}
	return destination;
}

size_t	ft_strlcpy(char *destination, const char *source, size_t dstsize)
{
	size_t	i;

	i = 0;

	if (!destination || !source)
		return 0;
	while (source[i] && i < dstsize - 1 && dstsize)
	{
		destination[i] = source[i];
		++i;
	}
	if (dstsize)
		destination[i] = '\0';

	return ft_strlen(source);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		++i;
	return i;
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	y;
	size_t	i;
	char	*str;

	i = 0;
	y = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[y])
		str[i++] = s2[y++];
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*res;

	i = 0;
	if ((res = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1)) != NULL)
	{
		while (s1[i])
		{
			res[i] = s1[i];
			i++;
		}
		res[i] = '\0';
		return (res);
	}
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	length;

	i = 0;
	length = ft_strlen(s);
	while (i <= length)
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return (char *)s + i;
		++i;
	}
	return NULL;
}

