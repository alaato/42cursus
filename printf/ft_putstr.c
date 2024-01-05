/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatarban <aatarban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:31:10 by aatarban          #+#    #+#             */
/*   Updated: 2023/12/09 21:31:10 by aatarban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
#include <unistd.h>

void	ft_putstr(char *s)
{
	int size;

	size = ft_strlen(s);
	write(1, s, size);
}