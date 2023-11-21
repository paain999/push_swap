/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 03:31:37 by dajimene          #+#    #+#             */
/*   Updated: 2021/07/23 03:18:01 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	int	ft_arrlen(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

static	char	**is_one_arg(char **av, t_stack *stack_a, int ac, char **arr)
{
	int	i;

	if (ac == 2)
	{
		arr = ft_split(av[1], ' ');
		i = ft_arrlen(arr);
		if (i < 2)
			ft_error_exit(NULL, arr);
		stack_a->size = i;
		stack_a->max_size = stack_a->size;
		return (arr);
	}
	return (NULL);
}

char	**ft_split_args(int ac, char **av, t_stack *stack_a)
{
	char	**arr;
	int		i;

	arr = NULL;
	arr = is_one_arg(av, stack_a, ac, arr);
	if (!arr)
	{
		i = 1;
		arr = malloc(sizeof(char *) * ac);
		if (!arr)
			ft_error_exit(NULL, arr);
		while (i < ac)
		{
			arr[i - 1] = ft_strdup(av[i]);
			i++;
		}
		arr[ac] = (void *)0;
		stack_a->size = ft_arrlen(arr);
		stack_a->max_size = stack_a->size;
	}
	return (arr);
}

int	*ft_parse_args(char **arr, int size)
{
	int	*stack;
	int	i;

	stack = NULL;
	stack = malloc(sizeof(int *) * size);
	if (!stack)
		ft_error_exit(NULL, arr);
	i = 0;
	while (i < size)
	{
		stack[i] = ft_atoi(arr[i]);
		i++;
	}
	return (stack);
}
