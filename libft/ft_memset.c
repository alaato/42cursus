/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatarban <aatarban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:03:25 by aatarban          #+#    #+#             */
/*   Updated: 2023/11/28 16:34:04 by aatarban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memset(void *str, int ch, size_t byte)
{
	unsigned char	*p;
	unsigned char	c;
	size_t			i;

	p = str;
	i = 0;
	c = (unsigned char)ch;
	while ((i < byte))
	{
		p[i] = c;
		i++;
	}
	return ((void *)p);
}
// int main(void)
// {
// 	char tab[100];
// 	memset(tab, 0, 100);
// 	ft_memset(tab, 'A', 0);
// 	if(tab[0] == 0)
// 		printf("first check ok %c\n", tab[0]);
// 	ft_memset(tab, 'A', 42);
// 	// int i = 0;
// 	// while (i < 42)
// 	// {
// 	// 	printf("the value of i is %d %d \n",i, tab[i]);
// 	// 	i++;
// 	// }
// 	// if(i == 5 && tab[5] == 0)
// 	// 	printf("second check ok %c", tab[42]);
// 	// else
// 	// 	printf("second check not ok %d and i is %d", tab[42], i);
// 	return (0);
// }
