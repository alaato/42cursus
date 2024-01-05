/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatarban <aatarban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:32:13 by aatarban          #+#    #+#             */
/*   Updated: 2023/12/10 17:05:00 by aatarban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = -1;
	while (str[++len])
		;
	return (len);
}
void	ft_putchar(char c, int* count)
{
	write(1, &c, 1);
	*count++;
}
void	ft_putstr(char *s, int* count)
{
	int	size;

	
	if (!s)
		write(1, "(null)", 6);
	else
	{
		size = ft_strlen(s);
		*count += size;
		write(1, s, size);

	}
}

void	ft_putnbr(int n, int* count)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		ft_putnbr(n, count);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10, count);
		ft_putnbr(n % 10, count);
	}
	else if (n >= 0 && n < 10)
	{
		n = n + 48;
		write(1, &(n), 1);
		*count++;
	}
}

void	ft_puthex(unsigned long n, int sign ,int* sum)
{
    char hex[16] = "0123456789abcdef";
    char hex_up[16] = "0123456789ABCDEF";
    char result[16];
    unsigned long nbr;
    int count;

    nbr = n;
    count = 0;
    while((nbr) && ((nbr = nbr / 16) )> 0)
        count++;
    nbr = n;
    result[++count] = 0;
    while(nbr > 0){
        if(sign == 0)
            result[--count] = hex[nbr%16];
        else
            result[--count] = hex_up[nbr%16];
        nbr = nbr / 16;
    }
    ft_putstr(result, sum);
}

void	ft_putadress(unsigned long n, int* count)
{
	write(1, "0x", 2);
	*count += 2;
	ft_puthex(n, 0, count);
}
void	put_unsigned(int n, int* count)
{
	unsigned int	nbr;

	nbr = n;
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10, count);
		ft_putnbr(nbr % 10, count);
	}
	else if (nbr < 10)
	{
		nbr = nbr + 48;
		write(1, &(nbr), 1);
		*count++;
	}
}

int ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		i;
	int count;
	

	i = -1;
	count = 0;
	if (!*fmt)
		return (-1);
	va_start(args, fmt);
	while (fmt[++i])
	{
		if (fmt[i] != '%')
		{
			write(1, &fmt[i], 1);
			continue ;
		}
		if (fmt[i] == '%')
		{
			i++;
			if (fmt[i] == 'c')
				ft_putchar(va_arg(args, int), &count);
			else if (fmt[i] == 's')
				ft_putstr(va_arg(args, char *), &count);
			else if (fmt[i] == 'd' || fmt[i] == 'i')
				ft_putnbr(va_arg(args, int), &count);
			else if (fmt[i] == 'x')
				ft_puthex(va_arg(args, int), 0, &count);
			else if (fmt[i] == 'X')
				ft_puthex(va_arg(args, int), 1, &count);
			else if (fmt[i] == 'p')
				ft_putadress((unsigned long)va_arg(args, void *), &count);
			else if (fmt[i] == '%')
				ft_putchar('%', &count);
			else if (fmt[i] == 'u')
				put_unsigned(va_arg(args, int), &count);
		}
	}
	va_end(args);
	count = count +i;
	return (count);
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
int	main(void)
{
	int x = 545;
	char * p;
	int y = ft_printf("ft, %c  %s %i %d %x %X %% %u  %p end",'a',"helo", 48, -456465,456465, 456465, 456465, p);
	int z =  printf("\nor, %c  %s %i %d %x %X %% %u  %p end",'a', "helo", 48, -456465,456465, 456465, 456465, p);
	// int countog = 0;
	// int countft = 0;
	// printf("\nheres oringinal");
	// printf("\n%c", '0');
	// printf("\n %c ", '0');
	// printf("\n %c", '0' - 256);
	// printf("\n%c ", '0' + 256);
	// printf("\n %c %c %c ", '0', 0, '1');
	// printf("\n %c %c %c ", ' ', ' ', ' ');
	// printf("\n %c %c %c ", '1', '2', '3');
	// printf("\n %c %c %c ", '2', '1', 0);
	// printf("\n %c %c %c ", 0, '1', '2');
	// ft_printf("\nheres mine : ");
	// ft_printf("\n%c", '0');
	// ft_printf("\n %c ", '0');
	// ft_printf("\n %c", '0' - 256);
	// ft_printf("\n%c ", '0' + 256);
	// ft_printf("\n %c %c %c ", '0', 0, '1');
	// ft_printf("\n %c %c %c ", ' ', ' ', ' ');
	// ft_printf("\n %c %c %c ", '1', '2', '3');
	// ft_printf("\n %c %c %c ", '2', '1', 0);
	// ft_printf("\n %c %c %c ", 0, '1', '2');
	return (0);
}