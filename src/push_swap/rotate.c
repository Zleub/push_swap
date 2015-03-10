/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 17:38:00 by adebray           #+#    #+#             */
/*   Updated: 2015/03/09 23:50:51 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void		rotate_list(t_ps **list)
{
	int		swp;
	t_ps	*tmp;

	if (!(*list))
		return ;
	swp = (*list)->nbr;
	tmp = *list;
	while (tmp->next)
	{
		tmp->nbr = tmp->next->nbr;
		tmp = tmp->next;
	}
	tmp->nbr = swp;
}

void			ra(void)
{
	if (g_env.verbose)
		ft_printf("ra\n");
	rotate_list(&g_head);
}

void			rb(void)
{
	if (g_env.verbose)
		ft_printf("rb\n");
	rotate_list(&g_end);
}
