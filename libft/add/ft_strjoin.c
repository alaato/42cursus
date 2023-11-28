#include <stdio.h> 
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = -1;
	while (str[++len])
		;
	return (len);
}
char *ft_strjoin(const char *s1, const char *s2)
{
    size_t s1_len;
    size_t s2_len;
    size_t	len;
    size_t  j;
    char    *joined;

    len = -1;
    s1_len = ft_strlen(s1);
    s2_len = ft_strlen(s2);
    joined = malloc((s1_len + s2_len +1) * sizeof(char));
    if (!joined)
        return NULL;
    while (++len < s1_len)
        joined[len] = s1[len];
    j = -1;
    len--;
    while (++len < (s1_len + s2_len))
        joined[len] = s2[++j];
    joined[len] = '\0';
    return (joined);
}

// int main ()
// {
//     char *test = "hello ";
//     char *test2 = "world";
//     char    *joined = ft_strjoin (test, test2);
//     printf("%s\n", joined);
// }