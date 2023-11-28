/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatarban <aatarban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:05:23 by aatarban          #+#    #+#             */
/*   Updated: 2023/11/28 16:16:22 by aatarban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*p;
	char	*p2;
	size_t	i;

	i = -1;
	p = (char *)src;
	p2 = (char *)dst;
	if (dst == NULL && src == NULL)
		return (dst);
	while (++i < n)
	{
		p2[i] = p[i];
	}
	return (dst);
}
// int main()
// {
// 	memcpy(((void*)0), ((void*)0), 0);

// }