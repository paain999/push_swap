/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:42:35 by dajimene          #+#    #+#             */
/*   Updated: 2023/11/22 10:42:26 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->stack);
	free(stack_b->stack);
	free(stack_a);
	free(stack_b);
}

void	ft_error_exit(t_stack *stack, char **splitted, int *i_arr)
{
	int	i;

	i = 0;
	if (splitted)
	{
		while (splitted[i])
			free(splitted[i++]);
		free(splitted);
	}
	if (i_arr)
		free(i_arr);
	if (stack)
	{
		free(stack->stack);
		free(stack);
	}
	ft_putstr_fd("Error\n", 2);
	exit(2);
}
