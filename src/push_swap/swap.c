/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 17:35:10 by adebray           #+#    #+#             */
/*   Updated: 2015/03/09 23:51:02 by adebray          ###   ########.fr       */
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

void			sa(void)
{
	if (g_env.verbose)
		ft_printf("sa\n");
	swap_list(&g_head);
}

void			sb(void)
{
	if (g_env.verbose)
		ft_printf("sb\n");
	swap_list(&g_end);
}
