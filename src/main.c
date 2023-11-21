/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:45:28 by dajimene          #+#    #+#             */
/*   Updated: 2021/07/23 03:25:09 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	char	**splitted_args;
	t_stack	*stack_b;
	int i = 0;

	splitted_args = NULL;
	if (argc < 2)
		return (0);
	ft_check_params(argc, argv);
	stack_a = ft_calloc(1, sizeof(t_stack));
	if (!stack_a)
		return (2);
	splitted_args = ft_split_args(argc, argv, stack_a);
	while (splitted_args[i])
		printf("STRINGS: %s\n", splitted_args[i++]);
	stack_a->stack = ft_parse_args(splitted_args, stack_a->size);
	i = 0;
	while (i < stack_a->size)
		printf("NUMBERS: %d\n", stack_a->stack[i++]);
	return (0);
}
