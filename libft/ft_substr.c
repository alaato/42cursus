/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatarban <aatarban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 23:23:43 by aatarban          #+#    #+#             */
/*   Updated: 2023/11/28 19:31:01 by aatarban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

// char *ft_substr(const char *s, unsigned int start, size_t len)
// {
//     size_t i;
//     char *str;

//     /* we first check that the string we received is not null
//      * if it's the case we return NULL as we won't be able to take
//      * a substring out of something empty
//      */
//     if (!s)
//         return (NULL);
//     /* if the start index is greater than the length of the original
//      * string we return an allocated empty string that can be freed
//      * later on
//      */
//     if (start > ft_strlen(s))
//         return (ft_strdup(""));
//     /* if the len we have to copy is greater than the length of the string
//      * starting at index start, that means we have to stop after we read
//      * the whole string and that the allocated size has not to be
//      * equal to the len received as parameter but only the size we will
//      * copy plus one for the NUL-terminating character
//      * this let's us only allocate memory that is really necessary
//      */
//     if (len > ft_strlen(s + start))
// 	{
// 		len = ft_strlen(s + start);
// 		printf("%zu ", ft_strlen(s + start));
// 	}
//     /* we then allocate the memory
//     */
//     str = ft_calloc(len + 1, sizeof(char));
//     if (!str)
//         return (NULL);
//     i = 0;
//     /* we then loop over the string received as parameter from index
//      * start + i and copy each character into our new string index i
//      */
//     while (i < len)
//     {
//         str[i] = s[start + i];
//         i++;
//     }
//     /* we finally return the substring
//      */
//     return (str);
// }
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
// int	main(void)
// {
// 	char *sub = ft_substr("i ama string please", 1, 3);
// 	printf("%s\n", sub);
// 	printf("%s\n", "hell ");
// }