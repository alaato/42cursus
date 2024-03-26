/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaa <alaa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 23:06:18 by alaa              #+#    #+#             */
/*   Updated: 2024/03/24 23:06:30 by alaa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_stack_size_3(int max, int min, t_stack *stack)
{
	t_node	*head;
	t_node	*tail;

	head = stack->head;
	tail = stack->tail;
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
void	sort_top_3(int max, int min, t_stack *a, t_stack *b)
{
	t_node	*head;
	t_node	*tail;
	t_node	*mid;

	head = a->head;
	mid = head->next;
	tail = mid->next;
	if (head->value == max && tail->value == min || head->value == max
		&& head->next->value == min || tail->value == max
		&& head->next->value == min)
		swap(a);
	if (a->head->next->next->value == min && a->head->next->value == max)
	{
		rotate(a);
		swap(a);
		reverse_rotate(a);
		swap(a);
	}
	else if (a->head->value == min && a->head->next->value == max)
	{
		push(a, b);
		swap(a);
		push(b, a);
	}
}
void	sort3(t_stack *a, t_stack *b)
{
	int	min;
	int	max;

	if (is_sorted(a))
		return ;
	set_min_max(&min, &max, a->head);
	if (a->size == 3)
		sort_stack_size_3(max, min, a);
	else if (a->size > 3)
		sort_top_3(max, min, a, b);
}
