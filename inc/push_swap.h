/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 17:35:49 by adebray           #+#    #+#             */
/*   Updated: 2015/05/17 01:57:54 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <ft_printf.h>

# include <limits.h>

typedef struct s_ps		t_ps;

struct					s_ps
{
	int					nbr;
	t_ps				*next;
};

t_ps					*g_head;
t_ps					*g_end;

void					sa(void);
void					sb(void);
void					print_list1(void);
void					print_list2(void);
void					pa(void);
void					pb(void);
void					ra(void);
void					rb(void);
void					rra(void);
void					rrb(void);
void					rrr(void);
void					ss(void);
void					rr(void);

int						is_sort(t_ps *list);
int						is_reverse_sort(t_ps *list);
int						get_listsize(t_ps *list);
int						get_listmin(t_ps *list);
int						get_listmax(t_ps *list);

void					die(int val);
void					create(int nbr);
int						check(char *str);

void					do_something(int nbr);

int						get_max_int(char *str);
int						get_min_int(char *str);

typedef struct s_env	t_env;

struct					s_env
{
	int					min;
	int					max;
	int					mid;
	int					middle;
	int					verbose;
};

enum					e_moves
{
	PA,
	PB,
	SA,
	SB,
	RA,
	RB,
	RRA,
	RRB,
	SS,
	RR,
	RRR
};

t_env		g_env;

#endif
