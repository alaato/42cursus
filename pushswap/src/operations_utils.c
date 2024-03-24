/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaa <alaa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:22:33 by alaa              #+#    #+#             */
/*   Updated: 2024/03/22 03:54:55 by alaa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*create_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	add_node(t_stack *stack, t_node *node)
{
	if (stack->size <= 0)
	{
		stack->head = node;
		stack->tail = node;
	}
	node->next = stack->head;
	node->prev = stack->tail;
	stack->tail->next = node;
	stack->head->prev = node;
	stack->head = node;
	stack->size++;
}

t_node	*extract_node(t_stack *stack)
{
	t_node	*temp;

	temp = malloc(sizeof(t_stack));
	if (!temp)
		return (NULL);
	stack->tail->next = stack->head->next;
	temp = stack->head;
	stack->head = stack->head->next;
	stack->head->prev = stack->tail;
	stack->size--;
	temp->next = NULL;
	temp->prev = NULL;
	return (temp);
}

void	print_stack(t_stack *stack)
{
	int		i;
	t_node	*curr;

	i = -1;
	curr = stack->head;
	write(1, "here is stack ", 15);
	write(1, &stack->name, 1);
	while (++i < stack->size)
	{
		ft_argument_c(32);
		ft_putnbr_fd(curr->value, 1);
		curr = curr->next;
	}
	ft_putchar_fd(10, 1);
}
