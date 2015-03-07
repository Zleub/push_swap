/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 17:38:52 by adebray           #+#    #+#             */
/*   Updated: 2015/03/07 17:39:24 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void		reverse_list(t_ps **list)
{
	t_ps	*tmp;

	if (!*list || !(*list)->next)
		return ;
	tmp = *list;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *list;
	*list = tmp->next;
	tmp->next = NULL;
}

void			reverse_l1(void)
{
	ft_printf("ra\n");
	reverse_list(&g_head);
}

void			reverse_l2(void)
{
	ft_printf("rb\n");
	reverse_list(&g_end);
}
