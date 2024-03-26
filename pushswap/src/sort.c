/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaa <alaa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 23:19:11 by alaa              #+#    #+#             */
/*   Updated: 2024/03/25 03:03:02 by alaa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort2(t_stack *stack)
{
	if (stack->head->value < stack->tail->value)
		swap(stack);
}

void	sort_a(t_stack *a, t_stack *b, int len)
{
	int	mid;
	int	rotated;

	if (is_sorted(a))
		return ;
	if (len == 2)
		return (sort2(a));
	else if (len == 3)
		return (sort3(a, b));
	mid = find_median(a);
	rotated = 0;
	while (a->size > (len / 2 + len % 2))
	{
		if (a->head->value < mid)
			push(a, b);
		else if (a->head->value >= mid && ++rotated)
			rotate(a);
		print_stack(a);
	}
	// while (len != a->size && pushed-- > 0)
	// 	reverse_rotate(a);
	sort_a(a, b, a->size);
}
void	sort(t_stack *a, t_stack *b)
{
	int size;

	size = a->size;
	if (size == 2)
		sort2(a);
	else if (size == 3)
		sort3(a, b);
	else if (size > 3)
		sort_a(a, b, a->size);
}