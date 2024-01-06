#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// size_t	ft_strlen(const char *str)
// {
// 	size_t	len;

// 	len = -1;
// 	while (str[++len])
// 		;
// 	return (len);
// }

// char	*ft_strchr(char const *str, int c)
// {
// 	while (*str)
// 	{
// 		if (*str == (char)c)
// 			return ((char *)str);
// 		str++;
// 	}
// 	if (*str == (char)c)
// 		return ((char *)str);
// 	else
// 		return (NULL);
// }

// char	*ft_strjoin( char *s1,  char *s2)
// {
// 	size_t	s1_len;
// 	size_t	s2_len;
// 	size_t	len;
// 	size_t	j;
// 	char	*joined;

// 	len = -1;
// 	s1_len = ft_strlen(s1);
// 	s2_len = ft_strlen(s2);
// 	joined = malloc((s1_len + s2_len + 1) * sizeof(char));
// 	if (!joined)
// 		return (NULL);
// 	while (++len < s1_len)
// 		joined[len] = s1[len];
// 	j = -1;
// 	len--;
// 	while (++len < (s1_len + s2_len))
// 		joined[len] = s2[++j];
// 	joined[len] = '\0';
// 	return (joined);
// }
// void	*ft_memcpy(void *dst, const void *src, size_t n)
// {
// 	char	*p;
// 	char	*p2;
// 	size_t	i;

// 	i = -1;
// 	p = (char *)src;
// 	p2 = (char *)dst;
// 	if (dst == NULL && src == NULL)
// 		return (dst);
// 	while (++i < n)
// 	{
// 		p2[i] = p[i];
// 	}
// 	return (dst);
// }
// char *ft_strndup (const char *s, size_t n)
// {
//   char *new = (char *) malloc (n + 1);
//   if (new == NULL)
// 	return (NULL);
//   new[n] = '\0';
//   return (char *) ft_memcpy(new, s, n);
// }

char	*trim_stash(char *start)
{
	int		len;
	int		i;
	char	*temp;

	len = ft_strlen(start);
	temp = malloc(sizeof(char) * (len + 1));
	i=-1;
	while (++i < len )
		temp[i] = start[i + 1];
	temp[len] = '\0';
	if(ft_strlen(temp) == 0 )
	{
		free(temp);
		return (NULL);
	}
	return (temp);
}
// if there is no newline just append stash to line and continue reading untill we find a new line.
// in case there is a new line, we have to append only up to the new line
//
char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	int			readret;
	char		*line;
	char		*newline;
	char		*temp;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	// read buffer size and check if buffer has new line if not continue.
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		
		free(stash);
		stash = NULL;
		free(buffer);
		return (NULL);
	}
	readret = 1;
	if(!stash)
		newline = NULL;
	else
		newline = ft_strchr(stash, '\n');

	
	while (readret > 0)
	{
		readret = read(fd, buffer, BUFFER_SIZE);
		if (readret < 0)
		{
			free(stash);
			free(buffer);
			return (NULL);
		}
		else if (readret == 0)
			break ;
		buffer[readret] = '\0';
		if (!stash)
			stash = ft_strndup("", 0);
		temp = stash;
		stash = ft_strjoin(stash, buffer);
		free(temp);
		temp = NULL;
		newline = ft_strchr(stash, '\n');
		if (newline)
			break ;
	}
	line = stash;
	free(buffer);
	if (newline)
	{
		line = ft_strndup(stash, (newline + 1 - stash));
		temp = stash;
		stash = trim_stash(newline);
		free(temp);
		newline = NULL;
	}
	else if (readret == 0)
	{
		if(line == NULL)
			return (NULL);
		stash = NULL;
	}
	return (line);
}

// int	main(void)
// {
// 	int fd = open("text.txt", O_RDONLY);
// 	char *array;
// 	for (size_t i = 1; i <= 4; i++)
// 	{
// 		if(i == 3)
// 			array = get_next_line(-1);
// 		else
// 			array = get_next_line(fd);
// 		printf("%s", array);
// 		if (array != NULL)
// 			free(array);
// 	}
// 	close(fd);
// 	fd = open("text.txt", O_RDONLY);
// 	for (size_t i = 1; i <= 5; i++)
// 	{
		
// 		array = get_next_line(fd);
// 		printf("%s", array);
// 		free(array);
// 	}
// 	return 0;
// }