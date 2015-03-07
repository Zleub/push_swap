/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 17:35:49 by adebray           #+#    #+#             */
/*   Updated: 2015/03/07 17:47:43 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <ft_printf.h>

typedef struct s_ps		t_ps;

struct					s_ps
{
	int					nbr;
	t_ps				*next;
};

t_ps					*g_head;
t_ps					*g_end;

void					swap_l1(void);
void					swap_l2(void);
void					print_list1(void);
void					print_list2(void);
void					push_l1(void);
void					push_l2(void);
void					reverse_l1(void);
void					reverse_l2(void);
void					rotate_l1(void);
void					rotate_l2(void);

#endif
