/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaa <alaa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 00:40:30 by alaa              #+#    #+#             */
/*   Updated: 2024/03/22 02:43:19 by alaa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	str_to_int(char *str, int numbers[], int len)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	if (!numbers)
		return (0);
	while (str[++i])
	{
		if (str[i] == ' ')
			j++;
		else
			numbers[j] = numbers[j] * 10 + (str[i] - 48);
	}
	return (j + 1);
}
void	fill_stack_many_args(int count, char **args, t_stack *stack)
{
	int	i;

	i = count;
	while (--i > 0)
		fill_stack(stack, args[i]);
}
void	fill_stack(t_stack *stack, char *input)
{
	int *numbers;
	int len;
	t_node *node;

	len = ft_strlen(input);
	numbers = ft_calloc(len, sizeof(int));
	len = str_to_int(input, numbers, len);
	while (--len >= 0)
	{
		node = create_node(numbers[len]);
		add_node(stack, node);
	}
	free(numbers);
}