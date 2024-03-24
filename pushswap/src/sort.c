/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaa <alaa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 23:19:11 by alaa              #+#    #+#             */
/*   Updated: 2024/03/23 01:55:05 by alaa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort3(t_stack *stack)
{
	t_node	*head;
	t_node	*tail;
	int		min;
	int		max;

	head = stack->head;
	tail = stack->tail;
	if (is_sorted(stack))
		return ;
	set_min_max(&min, &max, head);
	if (head->value == max && tail->value == min)
	{
		rotate(stack);
		swap(stack);
	}
	else if (tail->value == max && head->next->value == min)
		swap(stack);
	else if (tail->value == min && head->next->value == max)
		reverse_rotate(stack);
	else if (head->value == max && head->next->value == min)
		rotate(stack);
	else if (head->value == min && head->next->value == max)
	{
		swap(stack);
		rotate(stack);
	}
}

void	sort2(t_stack *stack)
{
	if (stack->head->value < stack->tail->value)
		swap(stack);
}

void	sort5(t_stack *a, t_stack *b)
{
	int		mid;
	int		i;
	t_node	*curr;

	if (is_sorted(a))
		return ;
	mid = find_median(a);
	i = a->size;
	curr = a->head;
	while (--i >= 0)
	{
		while (curr->value < mid && curr != a->head)
			rotate(a);
		if (curr->value < mid && curr == a->head)
		{
			push(a, b);
			curr = a->head;
		}
		else
			curr = curr->next;
	}
	sort(a, b);
}
void	sort(t_stack *a, t_stack *b)
{
	int size;

	size = a->size;
	if (size == 2)
		sort2(a);
	else if (size == 3)
		sort3(a);
	else if (size <= 5)
		sort5(a, b);
}