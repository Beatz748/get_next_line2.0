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
	size_t	s1_size;
	size_t	s2_size;
	char	*joined;

	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);

	if (!s1 || !s2)
		return 0x000;
	if (!(joined = (char *)malloc((s1_size + s2_size + 1) * sizeof(char))))
		return 0x000;
	ft_strlcpy(joined, s1, s1_size + 1);
	ft_strlcpy(joined + s1_size, s2, s2_size + 1);
	return joined;
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	l;

	l = ft_strlen(s1);
	s2 = (char *)malloc(l * sizeof(char));
	ft_memcpy(s2, s1, l);

	return s2;
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

