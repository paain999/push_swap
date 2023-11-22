/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:45:28 by dajimene          #+#    #+#             */
/*   Updated: 2023/11/22 12:26:37 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	char	**splitted;
	t_stack	*stack_b;
	int i = 0;

	splitted = NULL;
	if (argc < 2)
		return (0);
	ft_check_params(argc, argv);
	stack_a = ft_calloc(1, sizeof(t_stack));
	if (!stack_a)
		return (2);
	splitted = ft_split_args(argc, argv, stack_a);
	while (splitted[i])
		printf("STRINGS: %s\n", splitted[i++]);
	stack_a->stack = ft_parse_args(splitted, stack_a);
	stack_b = ft_calloc(1, sizeof(t_stack));
	if (!stack_b)
		return (2);
	stack_b->stack = ft_calloc(stack_a->size, sizeof(int));
	stack_b->size = 0;
	i = 0;
	while (i < stack_a->size)
		printf("NUMBERS: %d\n", stack_a->stack[i++]);
	ft_free_stacks(stack_a, stack_b);
	return (0);
}
