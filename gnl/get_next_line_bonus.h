# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
#include <stdio.h>


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10

# endif

char    *get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strchr(char const *str, int c);
char	*ft_strjoin( char *s1,  char *s2);
void	*ft_memcpy(void  *dst,  void const *src, size_t n);
char *ft_strndup (char const *s, size_t n);

#endif