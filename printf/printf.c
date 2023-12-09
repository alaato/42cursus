#include <stdarg.h>
#include <io.h>
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
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_putstr(char *s)
{
	int	size;

	size = ft_strlen(s);
	write(1, s, size);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		ft_putnbr(n);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else if (n >= 0 && n < 10)
	{
		n = n + 48;
		write(1, &(n), 1);
	}
}

void	ft_puthex(int n, int sign)
{
    char hex[16] = "0123456789abcdef";
    char hex_up[16] = "0123456789ABCDEF";
    char result[16];
    size_t nbr;
    int i;
    int count;

    nbr = n;
    count = 0;
    while((nbr) && ((nbr = nbr / 16) )> 0)
        count++;
    result[++count] = 0;
    nbr = n;
    while(nbr > 0){
        if(sign == 0)
            result[--count] = hex[nbr%16];
        else
            result[--count] = hex_up[nbr%16];
        nbr = nbr / 16;
    }
    ft_putstr(result);
}

void	ft_putadress(int n)
{
    ft_putstr("0x");
    ft_puthex(n, 1);
}
unsigned int put_unsigned(int n)
{
    unsigned int nbr;

    nbr = n;
	if (nbr> 9)
	{
		ft_putnbr(nbr/ 10);
		ft_putnbr(nbr% 10);
	}
	else if (nbr>= 0 && nbr< 10)
	{
		nbr= nbr+ 48;
		write(1, &(nbr), 1);
	}
}

int ft_printf(char *fmt, ...)
{
    va_list args;
    int i;

    i = -1;
    if(!*fmt)
        return(0);
    va_start(args, fmt);
    while (fmt[++i])
    {
        if( fmt[i] != '%'){
            write(1, &fmt[i], 1);
            continue;
        }
        if (fmt[i] == '%')
        {
            i++;
            if(fmt[i] == 'c')
                ft_putchar(va_arg(args, int));
            else if(fmt[i] == 's')
                ft_putstr(va_arg(args, char*));
            else if(fmt[i] == 'd' || fmt[i] == 'i')
                ft_putnbr(va_arg(args, int));
            else if(fmt[i] == 'x')
                ft_puthex(va_arg(args, int), 0);
            else if(fmt[i] == 'X')
                ft_puthex(va_arg(args, int), 1);
            else if(fmt[i] == 'p')
                ft_putadress(va_arg(args, int));
            else if(fmt[i] == '%')
                ft_putchar('%');
            else if(fmt[i] == 'u')
                put_unsigned(va_arg(args, int));
        }
    }
    va_end(args);
    return(1);
}
void	ft_putbase_fd(int nbr, const char *base, int fd)
{
	int		base_len;
	long	nb;
	char	c;

	base_len = ft_strlen(base);
	if (nbr < 0)
	{
		write(fd, "-", 1);
		nb = -((long)nbr);
	}
	else
		nb = (long)nbr;
	if (nb > (base_len - 1))
		ft_putbase_fd(nb / base_len, base, fd);
	c = *(base + (nb % base_len));
	write(fd, &c, 1);
}
int main()
{

    int x = 545;
    int y = 100;
    // ft_putbase_fd(255, "01", 1);
    // ft_putbase_fd(-42, "0123456789ABCDEF", 1);
    // ft_printf("ft,  %s %i %d %x %X %% %u gg", "i am", 48, -15482, -53745, -53745, -53745);
    //  printf("\nor,  %s %i %d %x %X %% %u gg", "i am", 48, -15482, -53745, -53745, -53745);
    ft_printf("heres addres of x: %p", &x);
    printf("\nheres addres of x: %p", &x);

    return (0);
}