#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = -1;
	while (str[++len])
		;
	return (len);
}

void	ft_putendl_fd(char *s, int fd)
{
	int	size;

	size = ft_strlen(s);
	write(fd, s, size);
	write(fd, "\n", 1);
}

int	main(void)
{
	char    *s = "hello world";
	ft_putendl_fd(s, 1);
	char    *s2 = "hello world";
	ft_putendl_fd(s2, 1);

}
