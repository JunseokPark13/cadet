/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:03:21 by jupark            #+#    #+#             */
/*   Updated: 2021/06/01 19:19:39 by jupark           ###   ########.fr       */
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
}					t_stacks;

size_t				ft_strlen(char *str);
void				ft_putstr(char *str);
int					ft_atoi(const char *nptr);

t_node				*ft_nodenew(int num);
t_list				*ft_lstnew();
void				ft_lstadd_back(t_list *lst, t_node *new_n);
void				ft_lstadd_front(t_list *lst, t_node *new_n);

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

void				ft_quick_sort(int *ary, int left, int right);
void				ft_get_pivot(int *ary, int length, int *p1, int *p2);

void				A_to_B(t_stacks *stack, int size);

void				ft_printlst_front(t_list *lst);
void				ft_printlst_two(t_list *lst1, t_list *lst2);
#endif
