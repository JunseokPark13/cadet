/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:03:21 by jupark            #+#    #+#             */
/*   Updated: 2021/06/08 15:57:22 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# define ERRMSG "Error\n"

typedef struct		s_node
{
	int				num;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct		s_list
{
	t_node			*head;
	t_node			*tail;
	int				cnt;
}					t_list;

typedef struct		s_stacks
{
	t_list			*lst_a;
	t_list			*lst_b;
	int				p1;
	int				p2;
	int				ra_cnt;
	int				rb_cnt;
	int				p_cnt;
	int				isprint;
}					t_stacks;

int					check_duplicate(int *ary, int size);
t_stacks			*create_stacks(int *ary, int size);

void				ft_escape(int *ary);
int					*parse_argv(int argc, char *argv[], int *arylen);

size_t				ft_strlen(char *str);
void				ft_putstr(char *str);
int					ft_isdigit(char c);
int					ft_atoi(const char *nptr, int *ary);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				**ft_split(char const *s, char c);
int					ft_strchr(char const *s, char c);
int					ft_onlychr(char const *s, char c);

t_node				*ft_nodenew(int num);
t_list				*ft_lstnew();
t_stacks			*ft_stacknew(t_list *lst_a, t_list *lst_b);
void				ft_stackcnt_init(t_stacks *stack);

void				ft_lstadd_back(t_list *lst, t_node *new_n);
void				ft_lstadd_front(t_list *lst, t_node *new_n);

void				ft_listdelone(t_node *node);
void				ft_lstclear(t_list *lst);
void				ft_stacksclear(t_stacks *stack);

void				ft_sa(t_stacks *stack);
void				ft_sb(t_stacks *stack);
void				ft_ss(t_stacks *stack, int flag);

void				ft_pa(t_stacks *stack);
void				ft_pb(t_stacks *stack);

void				ft_ra(t_stacks *stack);
void				ft_rb(t_stacks *stack);
void				ft_rr(t_stacks *stack, int flag);

void				ft_rra(t_stacks *stack);
void				ft_rrb(t_stacks *stack);
void				ft_rrr(t_stacks *stack, int flag);

void				get_pivot(t_stacks *stack, t_list *lst, int size,
		int cs);
int					is_sorted(t_list *lst, int size, int dir);

void				rr_by_cnt(t_stacks *stack, int ra_cnt, int rb_cnt);
void				a_to_b(t_stacks *stack, int size);
void				b_to_a(t_stacks *stack, int size);
void				a_to_b_five(t_stacks *stack, int size);

void				ft_optimize(t_stacks *stack, int size, int st);

int					cmp_three(int a, int b, int c);
void				sort_two(t_stacks *stack, t_list *lst, int st);
void				sort_three(t_stacks *stack, t_list *lst, int st);

void				sort_a_notthree(t_stacks *stack, int a, int b, int c);
void				sort_b_notthree(t_stacks *stack, int a, int b, int c);

void				do_command(t_stacks *stack, char *cmd);
void				check_issorted(t_stacks *stack);
#endif
