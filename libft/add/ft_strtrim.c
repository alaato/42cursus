/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatarban <aatarban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:29:59 by aatarban          #+#    #+#             */
/*   Updated: 2023/11/28 11:29:59 by aatarban         ###   ########.fr       */
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

int	found_in(char ch, const char *str)
{
	size_t	len;
	int		found;

	len = -1;
	found = 0;
	while (str[++len])
	{
		if (str[len] == ch)
		{
			found = 1;
			break ;
		}
	}
	return (found);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tmp;
	size_t			i;

	i = 0;
	tmp = malloc(count * size);
	if (!tmp)
		return (NULL);
	while (i < count * size)
		tmp[i++] = 0;
	return (tmp);
}

char	*ft_strtrim(const char *src, const char *set)
{
	char	*trimmed;
	size_t	i;
	size_t	src_len;
	size_t	set_len;
	size_t	j;

	i = -1;
	j= -1;
	src_len = ft_strlen(src);
	set_len = ft_strlen(set);
	trimmed = ft_calloc((src_len -set_len +1), sizeof(char));
	if (!trimmed)
		return (NULL);
	while (++i <src_len)
	{
		if (found_in(src[i], set) == 0)
			trimmed[++j] = src[i];
	}
	trimmed[i] = '\0';
	return (trimmed);
}

// int main()
// {

// 	char *test = ft_strtrim("heblblob mbyb lbaobvaelbaya kbsuasbhnibk", "ba");
// 	printf("original: %s", "heblblob mbyb lbaobvaelbaya kbsuasbhink");
// 	printf("\nTesting: %s\n", test);
// }