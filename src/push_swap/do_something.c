/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_something.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/17 01:20:09 by adebray           #+#    #+#             */
/*   Updated: 2015/05/17 01:35:01 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void		do_something_under_lock(void)
{
	if (get_listmax(g_end) == g_end->nbr)
		pb();
	else
		rb();
}

static int		do_something_basic(void)
{
	if (g_head->next && g_head->nbr > g_head->next->nbr)
	{
		sa();
		return (1);
	}
	else if (g_head->nbr == g_env.max && get_listsize(g_head) != 1)
	{
		rra();
		return (1);
	}
	return (0);
}

static void		do_really_something(void)
{
	static int	lock;

	if (lock)
	{
		do_something_under_lock();
		return ;
	}
	if (do_something_basic())
		return ;
	if (g_head->nbr == g_env.max && get_listsize(g_head) == 1)
		lock = 1;
	else if (get_listsize(g_head) != 1 && g_head->nbr != g_env.max)
	{
		pa();
		if (g_end->next && g_end->next->nbr > g_end->nbr)
		{
			ft_printf(" ");
			sb();
		}
	}
}

void			do_something(int nbr)
{
	if (nbr == 2)
		sa();
	if (nbr == 3)
	{
		if (g_head->nbr > g_head->next->nbr)
			sa();
		else
			rra();
	}
	if (nbr > 3)
		do_really_something();
}
