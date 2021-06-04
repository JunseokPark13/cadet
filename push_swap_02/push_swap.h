/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:03:21 by jupark            #+#    #+#             */
/*   Updated: 2021/06/04 20:54:01 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# define NOTENOUGHARG "NOT ENOUGH ARG\n"

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

size_t				ft_strlen(char *str);
void				ft_putstr(char *str);
int					ft_atoi(const char *nptr);
int					ft_lstcnt(t_list *lst);

t_node				*ft_nodenew(int num);
t_list				*ft_lstnew();
t_stacks			*ft_stacknew(t_list *lst_a, t_list *lst_b);
void				ft_lstadd_back(t_list *lst, t_node *new_n);
void				ft_lstadd_front(t_list *lst, t_node *new_n);

void				ft_num__swap(t_node *n1, t_node *n2);
void				ft_stackcnt_init(t_stacks *stack);
void				ft_listdelone(t_node *node);
void				ft_lstclear(t_list *lst);

void				ft_sa(t_stacks *stack);
void				ft_sb(t_stacks *stack);
void				ft_ss(t_stacks *stack);

void				ft_pa(t_stacks *stack);
void				ft_pb(t_stacks *stack);

void				ft_ra(t_stacks *stack);
void				ft_rb(t_stacks *stack);
void				ft_rr(t_stacks *stack);

void				ft_rra(t_stacks *stack);
void				ft_rrb(t_stacks *stack);
void				ft_rrr(t_stacks *stack);

void				ft_move(t_list *lst, int dir);
void				ft_push(t_list *lst1, t_list *lst2);

void				get_pivot(t_stacks *stack, t_list *lst, int size,
		int cs);
int					is_sorted(t_list *lst, int size, int dir);

void				a_to_b(t_stacks *stack, int size);
void				b_to_a(t_stacks *stack, int size);
void				a_to_b_five(t_stacks *stack, int size);
void				b_to_a_five(t_stacks *stack, int size);

void				ft_optimize(t_stacks *stack, int size, int st);

int					cmp_three(int a, int b, int c);
int					lstnum_check(t_list *lst, t_node *head, int piv);
void				sort_two(t_stacks *stack, t_list *lst, int st);
void				sort_three(t_stacks *stack, t_list *lst, int st);

void				sort_a_notthree(t_stacks *stack, t_node *a, t_node *b,
		t_node *c);
void				sort_b_notthree(t_stacks *stack, t_node *a, t_node *b,
		t_node *c);

void				ft_optimize(t_stacks *stack, int size, int st);

void				ft_printlst_front(t_list *lst);
void				ft_printlst_two(t_list *lst1, t_list *lst2);
void				tester(t_stacks *stack, char *str);
#endif
