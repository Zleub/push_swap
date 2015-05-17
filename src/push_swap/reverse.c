/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 17:38:52 by adebray           #+#    #+#             */
/*   Updated: 2015/05/16 21:40:11 by adebray          ###   ########.fr       */
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

void			rra(void)
{
	ft_printf("rra");
	reverse_list(&g_head);
}

void			rrb(void)
{
	ft_printf("rrb");
	reverse_list(&g_end);
}
