/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatarban <aatarban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 23:27:48 by aatarban          #+#    #+#             */
/*   Updated: 2023/12/09 23:38:22 by aatarban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned int n, int sign)
{
	char hex[16] = "0123456789abcdef";
	char hex_up[16] = "0123456789ABCDEF";
	char result[16];
	size_t nbr;
	int count;

	nbr = n;
	count = 0;
	while ((nbr) && ((nbr = nbr / 16)) > 0)
		count++;
	nbr = n;
	result[++count] = 0;
	while (nbr > 0)
	{
		if (sign == 0)
			result[--count] = hex[nbr % 16];
		else
			result[--count] = hex_up[nbr % 16];
		nbr = nbr / 16;
	}
	ft_putstr(result);
}