/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatarban <aatarban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 23:35:00 by aatarban          #+#    #+#             */
/*   Updated: 2023/11/26 23:35:00 by aatarban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = -1;
	while (str[++len])
		;
	return (len);
}

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
	const char *s2 = "string";
	char *result = ft_strnstr(s1, s2, 12);	
	if (result == NULL)
		printf("no found", s1);
	else
		printf("result after ft %d\n", *result);
}*/