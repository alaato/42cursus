/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatarban <aatarban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:06:49 by aatarban          #+#    #+#             */
/*   Updated: 2023/11/28 16:11:19 by aatarban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (src == dst)
		return (dst);
	if (src > dst)
	{
		i = 0;
		while (i < len)
		{
			((char *)dst)[i] = ((const char *)src)[i];
			++i;
		}
	}
	else
	{
		i = len - 1;
		while (i != (size_t) - 1)
		{
			((char *)dst)[i] = ((const char *)src)[i];
			--i;
		}
	}
	return (dst);
}
// void	*ft_memmove(void *dst, const void *src, size_t n)
// {
// 	unsigned char	*p;
// 	unsigned char	*p2;
// 	unsigned char	temp[n];
// 	size_t			i;

// 	i = 0;
// 	p = (unsigned char *)src;
// 	p2 = (unsigned char *)dst;
// 	if (dst == NULL && src == NULL)
// 		return (dst);
// 	while (i < n && i < 128 * 1024 * 1024)
// 	{
// 		temp[i] = p[i];
// 		i++;
// 	}
// 	i = n;
// 	while (i >0 && i < 128 * 1024 * 1024)
// 	{
// 		p2[i] = temp[i];
// 		i++;
// 	}
// 	return (dst);
// }

// int main()
// {
//   printf("yes");

//     size_t size = 128 * 1024 * 1024;
//     char *dst = (char *)malloc(sizeof(char) * size);
//     char *data = (char *)malloc(sizeof(char) * size);

//     if (!dst || !data) {
//         fprintf(stderr, "Memory allocation failed\n");
//         return (1);  // Return an error code
//     }

//     memset(data, 'A', size);
//     ft_memmove(dst, data, size);
//     printf("yes");

//     // Don't forget to free allocated memory when done using it
//     free(dst);
//     free(data);

//     return (0);
// }