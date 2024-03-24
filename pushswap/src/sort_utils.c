/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaa <alaa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 03:37:30 by alaa              #+#    #+#             */
/*   Updated: 2024/03/22 03:37:44 by alaa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_stack *stack)
{
	int		i;
	t_node	*curr;

	curr = stack->head;
	i = 0;
	while (++i < stack->size)
	{
		if (curr->value > curr->next->value)
			return (0);
		curr = curr->next;
	}
	return (1);
}

void	set_min_max(int *min, int *max, t_node *head)
{
	int		i;
	t_node	*curr;

	i = -1;
	curr = head->next;
	*min = head->value;
	*max = head->value;
	while (++i < 2)
	{
		if (curr->value > *max)
			*max = curr->value;
		else if (curr->value < *min)
			*min = curr->value;
		curr = curr->next;
	}
}
