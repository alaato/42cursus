#include <stdio.h>
#include <string.h>
int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    int i;

    i = 0;
    while (i < n)
    {
         if(s1[i] != s2[i])
            return (s1[i]-s2[i]);
        i++;
    }
    return 0;
}
int main()
{
    const char *s1 = "";
    const char *s2 = "";
    int result = ft_strncmp(s1, s2, 4);
    printf("result after ft %d\n",result);
    int result2 = strncmp(s1, s2, 4);
    printf("result after original %d",result2);


}