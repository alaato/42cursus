/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatarban <aatarban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:57:39 by aatarban          #+#    #+#             */
/*   Updated: 2023/11/25 19:07:00 by aatarban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int argument)
{
	char	char_argument;

	char_argument = (char)argument;
	if (char_argument >= 65 && char_argument <= 90)
		return (1);
	if (char_argument >= 97 && char_argument <= 122)
		return (1);
	if (char_argument >= 48 && char_argument <= 57)
		return (1);
	else
		return (0);
}
