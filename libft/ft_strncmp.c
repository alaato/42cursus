/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: aatarban <aatarban@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2023/11/24 19:28:29 by aatarban          #+#    #+#             */
/*   Updated: 2023/11/24 19:28:29 by aatarban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		if (s1[i] == 0 || s2[i] == '\0')
			break ;
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	unsigned char s1[10] = "abcdef";
// 	unsigned char s2[10] = "abc\xfdxx";
// 	s1[3] = 0;
// 	s2[3] = 0;
// 	int result = ft_strncmp((char *)s1, (char *)s2, 7);
// 	printf("result after ft %d\n", result);
// 	int result2 = strncmp((char *)s1, (char *)s2, 7);
// 	printf("result after original %d", result2);
// }