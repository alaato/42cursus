#include "get_next_line.h"
size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = -1;
	while (str[++len])
		;
	return (len);
}

char	*ft_strchr(char const *str, int c)
{
    if(!str)
        return (NULL);
	else 
	{
		while (*str)
		{
			if (*str == (char)c)
				return ((char *)str);
			str++;
		}
		if (*str == (char)c)
			return ((char *)str);
		else
			return (NULL);
		}
}

char	*ft_strjoin( char *s1,  char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	len;
	size_t	j;
	char	*joined;

    if(!s1 || !s2)
        return (NULL);
	else
	{
		len = -1;
		s1_len = ft_strlen(s1);
		s2_len = ft_strlen(s2);
		joined = malloc((s1_len + s2_len + 1) * sizeof(char));
		if (!joined)
			return (NULL);
		while (++len < s1_len)
			joined[len] = s1[len];
		j = -1;
		len--;
		while (++len < (s1_len + s2_len))
			joined[len] = s2[++j];
		joined[len] = '\0';
		return (joined);
	}
}
void	*ft_memcpy(void *dst,  void *src, size_t n)
{
	char	*p;
	char	*p2;
	size_t	i;

	i = -1;
	if(!dst || !src)
		return (NULL);
	p = (char *)src;
	p2 = (char *)dst;
	if (dst == NULL && src == NULL)
		return (dst);
	while (++i < n)
	{
		p2[i] = p[i];
	}
	return (dst);
}
char *ft_strndup ( char *s, size_t n)
{
    char *new ;
	if(!s)
		return (NULL);
    new = (char *) malloc(n + 1);
    if (new == NULL)
    return (NULL);
    new[n] = '\0';
    return (char *) ft_memcpy(new, s, n);
}
