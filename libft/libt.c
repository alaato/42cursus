#include <stdio.h>
#include <string.h>
int ft_isalpha(int argument)
{
    char char_argument = (char)argument;
    if(char_argument >=65 && char_argument <= 90)
        return (1);
    else if (char_argument >=97 && char_argument <=122)
        return (2);
    else
        return (0);
}

int ft_isdigit( int argument )
{
    char char_argument = (char)argument;
    if(char_argument >=48 && char_argument <=57)
        return (1);
    else 
        return (0);

}
int ft_isalnum( int argument )
{
    char char_argument = (char)argument;
    if(char_argument >=65 && char_argument <= 90)
        return (1);
    if(char_argument >=97 && char_argument <=122)
        return (1);
    if(char_argument >=48 && char_argument <=57)
        return (1);
    else
        return (0);

}
int ft_isascii(int argument)
{
    char char_argument = (char)argument;
    if (char_argument >0 && char_argument <128)
        return (1);
    else
        return (0);

}
int ft_isprint( int argument )
{
    char char_argument = (char)argument;
    if (char_argument >= 32 && char_argument <=126)
        return  (1);
    else
        return (0);
}
size_t ft_strlen ( const char * str )
{
    size_t len = -1;
    while(str[++len]);
    return len;
}

void *ft_memset ( void *str , int ch, size_t byte ) 
{
    unsigned char *p ;
    p = str;
    int i;
    i = 0;
    while (p[i] && (i < byte))
    {
        p[i] = ch;
        i++;
    }
    return (str);
}
void    ft_bzero(void *s, size_t n)
{   
    int	i;
    char	*p;
    
    p = (char *) s;
	i = 0;

    while (p[i] && i < n)
    {
        p[i] = '\0';
        i++;
		
    }
	
}
void *ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*p;
	char	*p2;
	int i;

	i = 0;
	p = (char *) src;
	p2 = (char *) dst;

	while(i < n)
	{
		p2[i] = p[i];
		i++;
	}
	return (dst);

}
void *ft_memmove(void *dst, const void *src, size_t n)
{
	char    *p;
	char    *p2;
    char    *temp;
	int i;

	i = 0;
	p = (char *) src;
	p2 = (char *) dst;

	while(i < n)
	{
		temp[i] = p[i];
		i++;
	}
    i = 0;
    while(i < n)
	{
		p2[i] = temp[i];
		i++;
	}
	return (dst);
}
size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
int dstsize;
dstsize = 0;
size_t srclen = ft_strlen(src);
while(dstsize < size &&(src[dstsize]))
{
    dst[dstsize] = src[dstsize];
    dstsize++;
}
dst[dstsize] = '\0';
return srclen;
}
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
    size_t srclen = ft_strlen(src);
    size_t dstlen = ft_strlen(dst);

    if(dstlen == srclen)
        return (dstlen + srclen);
    if(dstsize > (dstlen + srclen)) {
        while(dstlen < dstsize)
        {
            dst[dstlen] = src[dstlen];
            dstlen++;
        }
    }
    
    /* else, concatenate dstsize character maximum */
}
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

char *ft_strrchr2(const char *s, int c)
{
    unsigned int i;
    char *res;
    char cc;
    
    cc = (char) c;
    res = NULL;
    i = 0;
    while (s[i])
    {
        if (s[i] == cc)
            res = (char *) &s[i];
        i++;
    }
    if (s[i] == cc)
        res = (char *) &s[i];
    return (res);
}
int main()
{
    // const char src[5] = "abcde";
    // char dest[6];
    // strlcpy(dest,"heloo", 5);
    // printf("after strcpy dest = %s\n", dest);
    // int dst_size = ft_strlcpy(dest,"helooooooo",3);
    // printf("After ft_strcpy dest = %s and size is %d\n", dest, dst_size);
    

    return 0;
}