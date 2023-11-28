#include <stdio.h>
#include <string.h>
void *ft_memchr(const void *s, int c, size_t n)
{
    /* as said in the man, the search is done for c converted to
     * an unsigned char, so we have to convert both c and s to 
     * unsigned char
     */
    unsigned char ch = (unsigned char) c;

    unsigned char *str = (unsigned char*)s;
    /* loop over the byte string until our counter is equal to n */
    while (*str++ && n-- >0 )
    {
    /* compare the current byte to c */
        /* if they are the same, return the address of this byte as a
         * void *
         */
        if (*str == ch)
            return ((void*)&*str);
    /* if we searched n bytes and didn't find what we were looking for
     * return NULL
     */
    }
    return NULL;
    /* as you can see, this is very close to the strchr and strrchr
     * functions, so take a look at these before looking at the
     * solution
     */
}
int main ()
{
     char string[11] = "nk;m;m;m;lm";
    char *p = memchr(string, 'l', 11);
    printf("after memchr %d\n", p -string);
    char *p2 = ft_memchr(string, 'l',11);
    printf("after ft_memchr %d\n", p2-string);

}