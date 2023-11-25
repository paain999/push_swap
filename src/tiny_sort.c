/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:45:03 by dajimene          #+#    #+#             */
/*   Updated: 2023/11/25 19:37:28 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_stack_node	*find_highest(t_stack_node *stack)
{
	int				highest;
	t_stack_node	*highest_node;

	if (NULL == stack)
		return (NULL);
	highest = INT_MIN;
	while (stack)
	{
		if (stack->value > highest)
		{
			highest = stack->value;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

/*
 * When i have 3 nodes, easy to sort
 * 	~If the 1* is the biggest, ra (biggestto bottom)
 * 	~If the 2* is the biggest, rra (biggest to bottom)
 * 	~Now i have forcefully the Biggest at the bottom
 * 		so i just chek 1° and 2°
*/
void	tiny_sort(t_stack_node **a)
{
	t_stack_node	*highest_node;

	highest_node = find_highest(*a);
	if (*a == highest_node)
		ra(a, 0);
	else if ((*a)->next == highest_node)
		rra(a, 0);
	if ((*a)->value > (*a)->next->value)
		sa(a, 0);
}

/*
 * Handle input 5
*/
void	handle_five(t_stack_node **a, t_stack_node **b)
{
	while (stack_len(*a) > 3)
	{
		init_nodes(*a, *b);
		finish_rotation(a, find_smallest(*a), 'a');
		pb(b, a, 0);
	}
}
