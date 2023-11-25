/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:42:35 by dajimene          #+#    #+#             */
/*   Updated: 2023/11/24 22:15:58 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_free_arr(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
			free(arr[i++]);
		free(arr);
	}
}

void	ft_free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*curr;

	if (!stack)
		return ;
	curr = *stack;
	while (curr)
	{
		tmp = curr->next;
		free(curr);
		curr = tmp;
	}
	stack = NULL;
}

void	ft_error_free(t_stack_node **a, char **av)
{
	ft_free_stack(a);
	ft_free_arr(av);
	exit (2);
}
