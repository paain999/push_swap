/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_and_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 03:31:37 by dajimene          #+#    #+#             */
/*   Updated: 2024/01/29 16:17:02 by dajimene         ###   ########.fr       */
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

static	char	**is_one_arg(char **av, int ac, char **splitted)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		splitted = ft_split(av[1], ' ');
		i = ft_arrlen(splitted);
		if (i < 2)
			ft_error_free(NULL, splitted, "Error\n");
		return (splitted);
	}
	return (NULL);
}

char	**ft_split_args(int ac, char **av)
{
	char	**splitted;
	int		i;

	splitted = NULL;
	splitted = is_one_arg(av, ac, splitted);
	if (!splitted)
	{
		i = 1;
		splitted = ft_calloc(ac + 1, sizeof(char *));
		if (!splitted)
			return (NULL);
		while (i < ac)
		{
			splitted[i - 1] = ft_strdup(av[i]);
			i++;
		}
		splitted[ac] = (void *)0;
	}
	return (splitted);
}
