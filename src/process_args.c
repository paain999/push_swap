/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 03:31:37 by dajimene          #+#    #+#             */
/*   Updated: 2023/11/22 10:40:50 by dajimene         ###   ########.fr       */
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

static	char	**is_one_arg(char **av, t_stack *stack_a, int ac,
char **splitted)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		splitted = ft_split(av[1], ' ');
		i = ft_arrlen(splitted);
		if (i < 2)
			ft_error_exit(NULL, splitted, NULL);
		stack_a->size = i;
		stack_a->max_size = stack_a->size;
		return (splitted);
	}
	return (NULL);
}

char	**ft_split_args(int ac, char **av, t_stack *stack_a)
{
	char	**splitted;
	int		i;

	splitted = NULL;
	splitted = is_one_arg(av, stack_a, ac, splitted);
	if (!splitted)
	{
		i = 1;
		splitted = ft_calloc(ac + 1, sizeof(char *));
		if (!splitted)
			ft_error_exit(NULL, splitted, NULL);
		while (i < ac)
		{
			splitted[i - 1] = ft_strdup(av[i]);
			i++;
		}
		splitted[ac] = (void *)0;
		stack_a->size = ft_arrlen(splitted);
		stack_a->max_size = stack_a->size;
	}
	return (splitted);
}

static	int	is_duplicate(int *parsed, int size)
{
	int	i;
	int	k;

	i = 0;
	while (i < size)
	{
		k = 0;
		while (k < size)
		{
			if (parsed[i] == parsed[k] && k != i)
				return (1);
			k++;
		}
		i++;
	}
	return (0);
}

int	*ft_parse_args(char **splitted, t_stack *stack)
{
	int		*parsed;
	int		i;
	long	number;

	parsed = ft_calloc((stack->size + 1), sizeof(int));
	if (!parsed)
		return (NULL);
	i = 0;
	while (i < stack->size)
	{
		number = ft_atoi(splitted[i]);
		if (number > 2147483647 || number < -2147483648)
			ft_error_exit(stack, splitted, parsed);
		parsed[i++] = (int)number;
	}
	if (is_duplicate(parsed, stack->size))
		ft_error_exit(stack, splitted, parsed);
	i = 0;
	while (splitted[i])
		free(splitted[i++]);
	free(splitted);
	return (parsed);
}
