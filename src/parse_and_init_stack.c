/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_init_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:57:00 by dajimene          #+#    #+#             */
/*   Updated: 2024/01/31 13:38:02 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	int	ft_is_duplicate(t_stack_node *a, int nbr)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->value == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}

t_stack_node	*ft_last_node(t_stack_node *last)
{
	if (last == NULL)
		return (NULL);
	while (last->next)
		last = last->next;
	return (last);
}

/* Add a node to the stack. If the stack is empty,
the node is the head, else it's added to the end of the stack. */
static	void	ft_add_node(t_stack_node **stack, int nbr)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->value = nbr;
	if (!*stack)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = ft_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

// Init the stack with the given params and check for duplicates and overflows.
void	init_stack(t_stack_node **a, char **av)
{
	long	nbr;
	int		i;

	i = 0;
	while (av[i])
	{
		nbr = ft_atol(av[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			ft_error_free(a, av, "Error\n");
		if (ft_is_duplicate(*a, nbr))
			ft_error_free(a, av, "Error\n");
		ft_add_node(a, (int)nbr);
		i++;
	}
	ft_free_arr(av);
}
