/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatarban <aatarban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 23:07:37 by aatarban          #+#    #+#             */
/*   Updated: 2023/11/28 23:07:39 by aatarban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			s_len;
	char			*result;

	i = -1;
	s_len = ft_strlen(s);
	result = malloc((s_len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (++i < s_len)
	{
		result[i] = f(i, s[i]);
	}
	result[i] = '\0';
	return (result);
}
