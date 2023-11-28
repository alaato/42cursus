/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatarban <aatarban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:09:43 by aatarban          #+#    #+#             */
/*   Updated: 2023/11/25 19:09:43 by aatarban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int	find_needle(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	int		flag;

	i = -1;
	while (++i < len)
	{
		j = 0;
		if (haystack[i] == needle[0])
		{
			flag = 1;
			while (needle[++j])
			{
				if (!(haystack[i + j] == needle[j]) || (i + j) >= len)
				{
					flag = 0;
					break ;
				}
			}
			if (flag == 1)
				return (i);
		}
	}
	return (-1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	found_index;

	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	if (ft_strlen(haystack) == 0)
		return (NULL);
	found_index = find_needle(haystack, needle, len);
	if (found_index != -1)
		return ((char *)&haystack[found_index]);
	return (NULL);
}
/*int	main(void)
{
	const char *s1 = "I am a string";
	const char *s2 = "am";
	char *result = ft_strnstr(s1, s2, 4);
	printf("result after ft %zu\n", result - s1);
	char *result2 = strnstr(s1, s2, 4);
	printf("result after original %zu", result2 - s2);
	const char *largestring = "Foo Bar Baz";
	const char *smallstring = "Bar";
	char *ptr;

	ptr = strstr(largestring, smallstring);
}*/