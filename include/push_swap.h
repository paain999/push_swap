/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:57:46 by dajimene          #+#    #+#             */
/*   Updated: 2021/07/23 03:17:56 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../include/libft.h"

typedef struct s_stack
{
	int	*stack;
	int	size;
	int	max_size;
	int	middle;
}		t_stack;

void	ft_check_params(int ac, char **av);
void	ft_error_exit(t_stack *stack, char **arr);
void	ft_free_stacks(t_stack *stack_a, t_stack *stack_b);
char	**ft_split_args(int ac, char **av, t_stack *stack_a);
int		*ft_parse_args(char **arr, int size);

#endif