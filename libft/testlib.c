#include <stdio.h>
#include <string.h>

testIs()
{
    // test for all 5 functions
    char c;
    c = 'a';
    int i = 0;
    for (i = 'a'; i < 'z'; i++)
    {
        printf("\nResult when lowercase alphabet %c is passed to ft_aplpha: %d",i, ft_isalpha(i));
        printf("\nResult when lowercase alphabet %c is passed to ft_alnum: %d",i, ft_isalnum(i));
        printf("\nResult when lowercase alphabet %c is passed to ft_digit: %d",i, ft_isdigit(i));
        printf("\nResult when lowercase alphabet %c is passed to ascii: %d",i, ft_isascii(i));
        printf("\nResult when lowercase alphabet %c is passed to print: %d",i, ft_isprint(i));
    }
    for (i = 65; i <=90; i++)
    {
        printf("\nResult when uppercase alphabet %c is passed to ft_aplpha: %d",i, ft_isalpha(i));
        printf("\nResult when uppercase alphabet %c is passed to ft_alnum: %d",i, ft_isalnum(i));
        printf("\nResult when uppercase alphabet %c is passed to ft_digit: %d",i, ft_isdigit(i));
        printf("\nResult when uppercase alphabet %c is passed to ascii: %d",i, ft_isascii(i));
        printf("\nResult when uppercase alphabet %c is passed to print: %d",i, ft_isprint(i));    }
    for (i = 48; i <=57; i++)
    {
        printf("\nResult when number alphabet %c is passed to ft_aplpha: %d",i, ft_isalpha(i));
        printf("\nResult when number alphabet %c is passed to ft_alnum: %d",i, ft_isalnum(i));
        printf("\nResult when number alphabet %c is passed to ft_digit: %d",i, ft_isdigit(i));
        printf("\nResult when number alphabet %c is passed to ascii: %d",i, ft_isascii(i));
        printf("\nResult when number alphabet %c is passed to print: %d",i, ft_isprint(i));
    }
    c='+';
        printf("\nResult when non alphabet %c is passed to ft_aplpha: %d",i, ft_isalpha(i));
        printf("\nResult when non alphabet %c is passed to ft_alnum: %d",i, ft_isalnum(i));
        printf("\nResult when non alphabet %c is passed to ft_digit: %d",i, ft_isdigit(i));
        printf("\nResult when non alphabet %c is passed to ascii: %d",i, ft_isascii(i));
        printf("\nResult when non alphabet %c is passed to print: %d",i, ft_isprint(i));
    
    for(c = 0; c < 127; c++){
   	if (ft_isprint(c)!= 0)
        printf("%c ", c);
    }
    
}
void testMemCpy(void)
{
    const char src[50] = "https://www.tutorialspoint.com";
    char dest[50];
    strcpy(dest,"Heloooo!!");
    printf("Before memcpy dest = %s\n", dest);
    ft_memcpy(dest, src, 5);
    printf("After ft_memcpy dest = %s\n", dest);
    memcpy(dest, src, 5);
    printf("After memcpy dest = %s\n", dest);
}

void testBzero(void)
{
    char arr[50] = "This is string.h library function";
    ft_bzero(arr, 12);
    printf("ft_bzero: %s", arr);
    bzero(arr, 12);
    printf("bzero: %s", arr);

}
void testStrlen(void)
{
    // test for strlen
    char str[11]= "hello world";
    size_t len = strlen(str);
    size_t ft_len = ft_strlen(str);
    printf("len is %zu", len);
    printf("len is %zu", ft_len);
}
testMemMove()
{
    const char src[5] = "abcde";
    char dest[5];
    strcpy(dest,"Heloo");
    printf("Before memcpy dest = %s\n", dest);
    ft_memmove(dest, src, 2);
    printf("After ft_memcpy dest = %s\n", dest);
    memmove(dest, src, 2);
    printf("After memcpy dest = %s\n", dest);
}