/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: border <border@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 12:12:10 by border            #+#    #+#             */
/*   Updated: 2021/08/12 12:12:11 by border           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

# define TRUE  1
# define FALSE 0

# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_steps
{
	int				a_len;
	int				b_len;
	int				a_dest;
	int				b_dest;
}					t_steps;

typedef struct s_data
{
	int				*a;
	int				len;
}					t_data;

typedef struct s_stack
{
	int				data;
	int				step;
	int				dir;
	struct s_stack	*next;
}					t_stack;

typedef struct s_stacks
{
	int				cmd;
	int				a_len;
	int				b_len;
	int				min;
	int				max;
	int				mid;
	int				*sort;
	t_stack			*a;
	t_stack			*b;
}					t_stacks;

typedef struct s_all
{
	t_data			new;
	t_stacks		stks;
	t_list			*clear;
}					t_all;

void				ft_ra(t_stack **a);
void				ft_rb(t_stack **b);
void				ft_rr(t_stacks *s);
void				ft_rra(t_stack **a);
void				ft_rrb(t_stack **b);
void				ft_rrr(t_stacks *s);
void				ft_sa(t_stack *a);
void				ft_sb(t_stack *a);
void				ft_ss(t_stacks *s);
void				ft_pa(t_stacks *s);
void				ft_pb(t_stacks *s);
void				ft_dup_check(t_all *all);
void				ft_arr_dup_search(const int *dup, int len, t_list *lst);
void				ft_sort(t_stacks *stks, t_list *lst);
void				ft_sort3(t_stacks *stks);
void				ft_sort5(t_stacks *stks);
void				ft_quick_sort(int *arr, int start, int end);
void				ft_initial_sort(t_stacks *stks, t_list *lst);
void				ft_basic_sort(t_stacks *stks, t_list *lst);
void				ft_steps_markup(t_stack *b, int len);
void				ft_min_insertion_steps(t_stacks *stks, t_steps *steps);
void				ft_spec(t_stacks *stks, t_steps *steps);
void				ft_help_finding_place(t_stacks *s, t_stack *b, \
											int *action, int *buff);
int					ft_only_spaces(const char *str);
int					ft_is_sorted(t_data *new);
int					ft_is_valid_str(char **argv);
int					ft_num_avail(const char *str);
int					ft_str_valid(char *str);
int					ft_partition(int *arr, int start, int end);
int					ft_smaller_elm_detection(t_stack *a, int buff, int src);
int					ft_len_to_min(t_stack *a, int min);
void				ft_error(int key, t_list **free_list);
void				ft_arr_sep(char **argv, t_data *new, t_list *lst);
void				cmd_add(int cmd_key, t_stacks *s);
int					ft_place_search(t_stacks *s, t_stack *b, \
											t_steps *steps, int min);
t_stack				*ft_create_stack(const int *buff, int len, t_list *lst);
int					ft_stk_back(t_stack *s);
void				ft_sort4(t_stacks *stks);

#endif