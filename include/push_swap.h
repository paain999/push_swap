/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:57:46 by dajimene          #+#    #+#             */
/*   Updated: 2023/11/27 22:36:23 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"
# include <unistd.h>
# include <limits.h>

typedef struct s_stack_node
{
	int					value;
	int					current_pos;
	int					final_index;
	int					push_price;
	int					above_middle;
	int					cheapest;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
	struct s_stack_node	*target_node;
}		t_stack_node;

//**** free and errors:
void			ft_free_arr(char **arr);
void			ft_free_stack(t_stack_node **stack);
void			ft_error_free(t_stack_node **a, char **av);

//**** Checking and processing params:
void			ft_check_params(int ac, char **av);
char			**ft_split_args(int ac, char **av);

//**** Init stack and stack utils:
void			init_stack(t_stack_node **a, char **av);
int				stack_len(t_stack_node *stack);
int				is_sorted(t_stack_node *stack);
t_stack_node	*ft_last_node(t_stack_node *head);

//**** Algorithm:
t_stack_node	*return_cheapest(t_stack_node *stack);
t_stack_node	*find_smallest(t_stack_node *stack);
void			sa(t_stack_node **a, int checker);
void			sb(t_stack_node **b, int checker);
void			ss(t_stack_node **a, t_stack_node **b, int checker);
void			tiny_sort(t_stack_node **a);
void			handle_five(t_stack_node **a, t_stack_node **b);
void			finish_rotation(t_stack_node **stack,
					t_stack_node *top_node, char stack_name);
void			push_swap(t_stack_node **a, t_stack_node **b);
void			pa(t_stack_node **a, t_stack_node **b, int checker);
void			pb(t_stack_node **b, t_stack_node **a, int checker);
void			init_nodes(t_stack_node *a, t_stack_node *b);
void			set_cheapest(t_stack_node *b);
void			set_price(t_stack_node *a, t_stack_node *b);
void			set_current_position(t_stack_node *stack);
void			rrb(t_stack_node **b, int checker);
void			rra(t_stack_node **a, int checker);
void			rrr(t_stack_node **a, t_stack_node **b, int checker);
void			ra(t_stack_node **a, int checker);
void			rb(t_stack_node **b, int checker);
void			rr(t_stack_node **a, t_stack_node **b, int checker);

#endif