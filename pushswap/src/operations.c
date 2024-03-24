/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaa <alaa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:22:44 by alaa              #+#    #+#             */
/*   Updated: 2024/03/21 20:05:34 by alaa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_stack *from, t_stack *to)
{
	t_node	*node;

	node = extract_node(from);
	if (!node)
		return ;
	add_node(to, node);
	if (from->name == 'a')
		printf("pb\n");
	else
		printf("pa\n");
}

void	swap(t_stack *stack)
{
	t_node	*temp;

	if (stack->size == 2)
	{
		temp = stack->head;
		stack->head = stack->tail;
		stack->tail = temp;
	}
	else
	{
		temp = stack->head->next;
		stack->tail->next = temp;
		stack->head->next = temp->next;
		stack->head->prev = temp;
		temp->next->prev = stack->head;
		temp->next = stack->head;
		temp->prev = stack->tail;
		stack->head = temp;
	}
	if (stack->name == 'a')
		printf("sa\n");
	else
		printf("sb\n");
}

void	rotate(t_stack *stack)
{
	stack->tail = stack->head;
	stack->head = stack->head->next;
	if (stack->name == 'a')
		printf("ra\n");
	else
		printf("rb\n");
}

void	reverse_rotate(t_stack *stack)
{
	stack->head = stack->tail;
	stack->tail = stack->tail->prev;
	if (stack->name == 'a')
		printf("rra\n");
	else
		printf("rrb\n");
}
