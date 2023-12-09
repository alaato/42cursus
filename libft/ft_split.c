/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatarban <aatarban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 22:20:05 by aatarban          #+#    #+#             */
/*   Updated: 2023/11/28 22:21:51 by aatarban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	srclen;

	srclen = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start > srclen)
		return (ft_strdup(""));
	if (len >= srclen - start)
		len = srclen - start;
	sub = malloc(len + 1 * sizeof(char));
	if (!sub)
		return (NULL);
	i = -1;
	while (++i < len)
	{
		sub[i] = s[start + i];
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(s1);
	i = -1;
	copy = malloc(sizeof(char) * src_len + 1);
	if (copy == NULL)
		return (NULL);
	while (s1[++i])
		copy[i] = s1[i];
	copy[i] = '\0';
	return (copy);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = -1;
	while (str[++len])
		;
	return (len);
}

static void	ft_allocate(char **new, char const *s, char sep)
{
	char		**new_p;
	char const	*tmp;

	tmp = s;
	new_p = new;
	while (*tmp)
	{
		while (*s == sep)
			++s;
		tmp = s;
		while (*tmp && *tmp != sep)
			++tmp;
		if (*tmp == sep || tmp > s)
		{
			printf("%d\n", tmp-s);
			*new_p = ft_substr(s, 0, tmp - s);
			s = tmp;
			++new_p;
		}
	}
	*new_p = NULL;
}

static int	ft_count_words(char const *s, char sep)
{
	int	word_count;

	word_count = 0;
	while (*s)
	{
		while (*s == sep)
			++s;
		if (*s)
			++word_count;
		while (*s && *s != sep)
			++s;
	}
	return (word_count);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	int		size;

	if (!s)
		return (NULL);
	size = ft_count_words(s, c);
	new = (char **)malloc(sizeof(char *) * (size + 1));
	if (!new)
		return (NULL);
	ft_allocate(new, s, c);
	return (new);
}

// int main()
// {
// 	char **split = ft_split("    hello i am what you think   ",' ');
// 	while (**split)
// 	{
// 		printf("# word is : %s \n",*split);
// 		split++;
// 	}
// 	return 0;
// }