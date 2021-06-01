/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangcpar <sangcpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 04:02:49 by sangcpar          #+#    #+#             */
/*   Updated: 2021/06/01 12:08:19 by sangcpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct		s_list{
	int				content;
	struct s_list	*next;
}					t_list;

typedef struct		s_info{
	int				pivot;
	int				a_size;
	int				b_size;
	int				flag;
	int				max;
}					t_info;

void				put_msg(char *s);
int					num_chk(t_list **a);
void				sa(t_list **a, int i);
void				sb(t_list **b, int i);
void				ss(t_list **a, t_list **b, int i);
void				ra(t_list **a, int i);
void				rb(t_list **b, int i);
void				rr(t_list **a, t_list **b, int i);
void				rra(t_list **a, int i);
void				rrb(t_list **b, int i);
void				rrr(t_list **a, t_list **b, int i);
void				pb(t_list **a, t_list **b, int i);
void				pa(t_list **a, t_list **b, int i);
int					sort(t_list **lst);
int					lst_size(t_list **lst);
void				ft_swap(int *a, int *b);
int					find_min(t_list *list);
int					find_mid(t_list **a, int size);
int					find_max(t_list **lst);
int					find_pos(t_list **lst, int n);
void				add_stack(t_list **a, int n);
t_list				*create_list(int ac, char **av);
void				list_free(t_list *lst);
void				move_b(t_list **a, t_list **b, t_info **info);
void				push_max(t_list **a, t_list **b, t_info **info);
void				move_a(t_list **a, t_list **b, t_info **info);
void				resolve(t_list **a);
void				short_resolve(t_list **a);
void				add_stack(t_list **a, int n);

#endif
