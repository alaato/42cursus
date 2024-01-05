#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char    *get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strchr(char const *str, int c);
char	*ft_strjoin( char *s1,  char *s2);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char *ft_strndup (const char *s, size_t n);

#endif