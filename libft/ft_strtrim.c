/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatarban <aatarban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:29:59 by aatarban          #+#    #+#             */
/*   Updated: 2023/11/28 22:10:51 by aatarban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

// int	found_in(char ch, const char *str)
// {
// 	size_t	len;
// 	int		found;

// 	len = -1;
// 	found = 0;
// 	while (str[++len])
// 	{
// 		if (str[len] == ch)
// 		{
// 			found = 1;
// 			break ;
// 		}
// 	}
// 	return (found);
// }

// char	*ft_strtrim(const char *src, const char *set)
// {
// 	char	*trimmed;
// 	size_t	start;
// 	size_t	src_len;
// 	size_t	set_len;
// 	size_t	end;
// 	size_t	i;

// 	i = -1;
// 	start = -1;
// 	src_len = ft_strlen(src);
// 	end = src_len;
// 	if(src_len == 0)
// 		return (NULL);
// 	while (++start < src_len && found_in(src[start], set) == 1)
// 		set_len++;
// 	while (end > 0 && found_in(src[end], set) == 1)
// 		set_len++;
// 	trimmed = ft_calloc((src_len - set_len + 1), sizeof(char));
// 	if (!trimmed)
// 		return (NULL);
// 	start--;
// 	while (++start <src_len && start<end)
// 		trimmed[++i] = src[start];
// 	trimmed[end] = '\0';
// 	return (trimmed);
// }

int	trim_that_shit(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*trimmed(const char *s1, size_t start, size_t len)
{
	char	*str;
	size_t	i;

	if (len <= 0 || start >= ft_strlen(s1))
		return (ft_strdup(""));
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s1[start + i];
		i++;
	}
	return (str);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(s1) - 1;
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	while (trim_that_shit(set, s1[i]))
		i++;
	while (trim_that_shit(set, s1[j]))
		j--;
	return (trimmed(s1, i, j - (i - 1)));
}

// int main()
// {

// 	char *test = ft_strtrim("heblblob mbyb lbaobvaelbaya kbsuasbhnibk", "ba");
// 	printf("original: %s", "heblblob mbyb lbaobvaelbaya kbsuasbhink");
// 	printf("\nTesting: %s\n", test);
// }