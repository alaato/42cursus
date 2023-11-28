/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatarban <aatarban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:40:48 by aatarban          #+#    #+#             */
/*   Updated: 2023/11/27 10:40:48 by aatarban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*strdup(const char *s1)
{
	char	*copy;
	int		i;

	i = -1;
	copy = malloc(sizeof(s1));
	if (copy == NULL)
		return (NULL);
	while (s1[++i])
		copy[i] = s1[i];
	copy[i] = 0;
	return (*copy);
}
