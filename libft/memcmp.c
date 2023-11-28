#include <string.h>
#include <stdio.h>
int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    unsigned char *str1;
    unsigned char *str2;
    size_t i;
 
    /* converting s1 and s2 to unsigned char */   
    str1 = (unsigned char *) s1;
    str2 = (unsigned char *) s2;
    i = -1;
    while (++i < n)
    {
        if ((unsigned char) str1[i] != (unsigned char) str2[i]){
            if(str1[i]-str2[i] < 0) 
                return (-1);
            else
                return (1);
        }
        
    }
    return (0);
}
/*int main()
{
    const char *s1 = "gl";
    const char *s2 = "g;";
     int result2 = memcmp(s1, s2, 4);
    printf("result after original %d\n",result2);
    int result = ft_memcmp(s1, s2, 4);
    printf("result after ft %d\n",result);
}*/