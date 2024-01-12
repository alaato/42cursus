# include "get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

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
//     if(!str)
//         return (NULL);
// 	else 
// 	{
// 		while (*str)
// 		{
// 			if (*str == (char)c)
// 				return ((char *)str);
// 			str++;
// 		}
// 		if (*str == (char)c)
// 			return ((char *)str);
// 		else
// 			return (NULL);
// 		}
// }

// char	*ft_strjoin( char *s1,  char *s2)
// {
// 	size_t	s1_len;
// 	size_t	s2_len;
// 	size_t	len;
// 	size_t	j;
// 	char	*joined;

//     if(!s1 || !s2)
//         return (NULL);
// 	else
// 	{
// 		len = -1;
// 		s1_len = ft_strlen(s1);
// 		s2_len = ft_strlen(s2);
// 		joined = malloc(s1_len + s2_len +1);
// 		if (!joined)
// 			{
// 				printf("joined");
// 				return (NULL);}
// 		while (++len < s1_len)
// 			joined[len] = s1[len];
// 		j = -1;
// 		len--;
// 		while (++len < (s1_len + s2_len))
// 			joined[len] = s2[++j];
// 		joined[len] = '\0';
// 		return (joined);
// 	}
// }
// void	*ft_memcpy(void  *dst,  void const *src, size_t n)
// {
// 	char	*p;
// 	char	*p2;
// 	size_t	i;

// 	i = -1;
// 	if(!dst || !src)
// 		return (NULL);
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
// char *ft_strndup ( char const *s, size_t n)
// {
//     char *new ;
// 	if(!s)
// 		return (NULL);
//     new = (char *) malloc(n + 1);
//     if (new == NULL)
// {   
// 	printf("str");
// 	return (NULL);
// }    new[n] = '\0';
//     return (char *) ft_memcpy(new, s, n);
// }

char	*trim_stash(char *start)
{
	int		len;
	int		i;
	char	*temp;

    if (!start)
	{
		return (NULL);
	}

    else
    {
        len = ft_strlen(start);
        temp = malloc(len + 1);
        if(!temp)
				return(NULL);
        i=-1;
        while (++i < len && start[i + 1])
            temp[i] = start[i + 1];
        temp[i] = '\0';
        if(!temp || ft_strlen(temp) == 0 )
        {
            free(temp);
            return (NULL);
        }
        return (temp);
    }

}
// if there is no newline just append stash to line and continue reading untill we find a new line.
// in case there is a new line, we have to append only up to the new line
//
char	*get_next_line(int fd)
{
	static char	*stash[4096];
	char		*buffer;
	int			readret;
	char		*line;
	char		*newline;
	char		*temp;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
				stash[fd] = NULL;
				return (NULL);
	}
	// read buffer size and check if buffer has new line if not continue.
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(stash[fd]);
		stash[fd] = NULL;
		free(buffer);
		return (NULL);
	}
	readret = 1;
	if(!stash[fd])
		newline = NULL;
	else
		newline = ft_strchr(stash[fd], '\n');

	
	while (readret > 0)
	{
		readret = read(fd, buffer, BUFFER_SIZE);
		if (readret < 0)
		{
			free(stash[fd]);
			return(NULL);
		}
		
		if (readret == 0)
			break ;
		buffer[readret] = '\0';
		if (!stash[fd])
			stash[fd] = ft_strndup("", 0);
		temp = stash[fd];
		stash[fd] = ft_strjoin(stash[fd], buffer);
		free(temp);
		temp = NULL;
		newline = ft_strchr(stash[fd], '\n');
		if (newline)
			break ;
	}
	line = stash[fd];
	if (newline)
	{
		line = ft_strndup(stash[fd], (newline + 1 - stash[fd]));
		temp = stash[fd];
		stash[fd] = trim_stash(newline);
		free(temp);
		newline = NULL;
	}
	else if (readret == 0)
	{
		stash[fd] = NULL;
	}
    free(buffer);
	return (line);
}

// int	main(void)
// {
	   

// 	int fd ;
// 	fd = open( "text.txt", O_RDONLY);
// 	char *array;
// 	for (size_t i = 1; i <= 7; i++)
// 	{
// 		if(i == 10)
// 			array = get_next_line(-1);
// 		else
// 			array = get_next_line(fd);
// 		printf("%s", array);
// 		free(array);
// 	}
// 	return 0;
// }