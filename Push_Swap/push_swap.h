/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:22:07 by mel-atti          #+#    #+#             */
/*   Updated: 2024/05/12 18:09:15 by mel-atti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				price;
	bool			cheapest;
	bool			above_median;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

void	create_stack_a(t_stack **a, char **av, int ac);

void	create_stack_append(t_stack **a, long value);

void	min_to_top(t_stack **a);

void	push_swap_algo(t_stack **a, t_stack **b);

void	sort_three_nodes(t_stack **a);

void	mechanical_turk(t_stack **a, t_stack **b);

void	initialize_a_nodes(t_stack *a, t_stack *b);

void	get_index_median(t_stack *a);

void	find_target_node_for_a(t_stack *a, t_stack *b);

void	price_calculation_for_a(t_stack *a, t_stack *b);

void	config_a_cheapest(t_stack *a);

void	move_nodes_to_b(t_stack **a, t_stack **b);

void	ft_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest);

void	ft_rev_rot_both(t_stack **a, t_stack **b, t_stack *cheapest);

void	prepare_a_for_push(t_stack **a, t_stack *top_node);

void	prepare_b_for_push(t_stack **b, t_stack *top_node);

void	initialize_b_nodes(t_stack *a, t_stack *b);

void	find_target_node_for_b(t_stack *a, t_stack *b);

void	move_nodes_to_a(t_stack **a, t_stack **b);

t_stack	*find_cheapest_node(t_stack *a);

t_stack	*find_max_node(t_stack *a);

t_stack	*find_min_node(t_stack *a);

t_stack	*find_last_node(t_stack *a);

int		ft_stack_size(t_stack *a);

bool	check_if_sorted(t_stack *a);

int		check_valid_input(char *av);

void	free_exit_handel(t_stack **a, char *str);

int		exit_error(char *str);

void	ft_clean_stack(t_stack **a);

void	ft_free_split(char **split);

void	free_av_exit(char **av, char *str);

void	sa(t_stack **a, bool print);

void	sb(t_stack **b, bool print);

void	ss(t_stack **a, t_stack **b, bool print);

void	pa(t_stack **a, t_stack **b, bool print);

void	pb(t_stack **a, t_stack **b, bool print);

void	ra(t_stack **a, bool print);

void	rb(t_stack **b, bool print);

void	rr(t_stack **a, t_stack **b, bool print);

void	rra(t_stack **a, bool print);

void	rrb(t_stack **b, bool print);

void	rrr(t_stack **a, t_stack **b, bool print);

int		check_for_duplicates(t_stack *a, long value);

void	err_clean_everything(t_stack **a, char **av, int ac);

long	ft_atol(const char *str);

size_t	ft_strlcpy(char *dst, const char *src, size_t dsize);

int		ft_strlen(char *str);

char	**ft_split(const char *s, char d);

int		av_error(char **av);

char	*join_avs(char **av);

char	**split_them(char *line);

char	*ft_strjoin2(char *s1, char *s2);

char	*ft_str_append(char *s1, char *s2, char *result);

#endif
