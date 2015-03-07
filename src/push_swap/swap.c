/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 17:35:10 by adebray           #+#    #+#             */
/*   Updated: 2015/03/07 17:46:43 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void		swap_list(t_ps **list)
{
	t_ps	*swp;

	if (!*list || !(*list)->next)
		return ;
	swp = *list;
	*list = (*list)->next;
	swp->next = (*list)->next;
	(*list)->next = swp;
}

void			swap_l1(void)
{
	ft_printf("sa\n");
	swap_list(&g_head);
}

void			swap_l2(void)
{
	ft_printf("sb\n");
	swap_list(&g_end);
}
