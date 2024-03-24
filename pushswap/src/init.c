/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaa <alaa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 03:54:39 by alaa              #+#    #+#             */
/*   Updated: 2024/03/22 03:57:00 by alaa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	init_stack(t_stack *stack, char name)
{
	stack->size = 0;
	stack->head = NULL;
	stack->tail = NULL;
	stack->name = name;
	return (0);
}
int	init_program(t_program *program, t_stack *a, t_stack *b)
{
	init_stack(a, 'a');
	init_stack(b, 'b');
	program->a = a;
	program->b = b;
}