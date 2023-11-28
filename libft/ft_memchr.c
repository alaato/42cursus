/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatarban <aatarban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:08:17 by aatarban          #+#    #+#             */
/*   Updated: 2023/11/25 19:08:17 by aatarban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*str;
	size_t			i;

	i = -1;
	ch = (unsigned char)c;
	str = (unsigned char *)s;
	while ((++i < n))
	{
		if (str[i] == ch)
			return ((void *)&str[i]);
	}
	return (NULL);
}
/*int main ()
{
		char string[11] = "nk;m;m;m;lm";
	char *p = memchr(string, 'l', 11);
	printf("after memchr %d\n", p -string);
	char *p2 = ft_memchr(string, 'l',11);
	printf("after ft_memchr %d\n", p2-string);

}*/