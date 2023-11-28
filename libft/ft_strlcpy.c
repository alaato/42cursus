/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatarban <aatarban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:07:44 by aatarban          #+#    #+#             */
/*   Updated: 2023/11/28 16:33:16 by aatarban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	dstsize;
	size_t	srclen;

	dstsize = -1;
	srclen = ft_strlen(src);
	if (size == 0)
		return (srclen);
	while (++dstsize < size - 1 && (src[dstsize]))
	{
		dst[dstsize] = src[dstsize];
	}
	dst[dstsize] = '\0';
	return (srclen);
}
