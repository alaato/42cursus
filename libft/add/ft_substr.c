/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatarban <aatarban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 23:23:43 by aatarban          #+#    #+#             */
/*   Updated: 2023/11/27 23:23:43 by aatarban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = -1;
	while (str[++len])
		;
	return (len);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	srclen;

	i = -1;
	srclen = ft_strlen(s);
	if (start > srclen)
		return (NULL);
	if (len == 0 || srclen == 0)
		return (NULL);
	if (len > srclen)
		len = srclen;
	sub = malloc(len + 1 * sizeof(char));
	if (sub == NULL)
		return (NULL);
	while (++i < len)
	{
		sub[i] = s[start + i];
	}
	sub[i] = '\0';
	return (sub);
}
// int	main(void)
// {
// 	char *sub = ft_substr("i ama string please", 1, 3);
// 	printf("%s\n", sub);
// 	printf("%s\n", "hell ");
// }