#include <stdio.h>
#include <string.h>
char *ft_strrchr(const char *s, int c)
{
    char *last;
    int i;

    i = -1;
    last = NULL;
    while(s[++i])
    {
        if (s[i] == (char) c)
            last = (char *)&s[i];
    }
    if (s[i] == (char) c)
        last = (char *)&s[i];
  return last;
}

int main (){
    char string[11] = "n";
    char *p = strrchr(string, '\0');
    printf("after strchr %d\n", p -string);
    char *p2 = ft_strrchr(string, '\0');
    printf("after ft_strchr %d\n", p2-string);
}