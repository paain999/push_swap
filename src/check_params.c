/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:44:40 by dajimene          #+#    #+#             */
/*   Updated: 2024/01/31 14:46:32 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_sign(int c)
{
	return (c == '+' || c == '-');
}

static void	ft_is_valid_arg(char *av, int ac)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if ((!ft_isdigit(av[i]) && !ft_sign(av[i]) && av[i] != ' ' && ac == 2) ||(!ft_isdigit(av[i]) && !ft_sign(av[i]) && ac > 2))
			error_exit("Error\n");
		else if (i != 0 && ft_sign(av[i]) && av[i - 1] != ' ' )
			error_exit("Error\n");
		else if (ft_sign(av[i]) && !ft_isdigit(av[i + 1]))
			error_exit("Error\n");
		i++;
	}
}

static int	ft_empty_args(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

void	ft_check_params(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '\0')
			error_exit("Error\n");
		i++;
	}
	i = 1;
	while (i < ac)
	{
		if (ft_empty_args(av[i]))
			error_exit("Error\n");
		ft_is_valid_arg(av[i], ac);
		i++;
	}
}
