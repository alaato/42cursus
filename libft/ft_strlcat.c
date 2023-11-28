/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatarban <aatarban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:18:24 by aatarban          #+#    #+#             */
/*   Updated: 2023/11/28 16:34:48 by aatarban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char			*d;
	const char		*s = src;
	unsigned long	n;
	unsigned long	dlen;

	d = dst;
	n = size;
	while (n-- != 0 && *d != '\0')
		d++;
	dlen = d - dst;
	n = size - dlen;
	if (n == 0)
		return (dlen + ft_strlen(s));
	while (*s != '\0')
	{
		if (n != 1)
		{
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';
	return (dlen + (s - src));
}

/*int main()
{
		char first[] = "This is ";
	char last[] = "a potentially long string";
	int r;
	int size = 16;
	char buffer[size];

	strcpy(buffer,first);
	r = strlcat(buffer,last,size);

	puts(buffer);
	printf("Value returned: %d\n",r);
	if( r > size )
		puts("String truncated");
	else
		puts("String was fully copied");

	return(0);
}*/