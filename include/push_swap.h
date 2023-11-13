/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:57:46 by dajimene          #+#    #+#             */
/*   Updated: 2023/11/13 13:01:48 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../include/libft.h"

typedef struct s_stack
{
	int *stack;
	int size;
	int max_size;
	int middle;
}		t_stack;

void	check_params(int ac, char **av);

#endif