/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 04:17:50 by adebray           #+#    #+#             */
/*   Updated: 2015/03/05 05:24:48 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

#define FTNBR 4

typedef struct s_list	t_list;

enum		e_ft
{
	SWAP,
	PUSH,
	ROTATE,
	REVERSE
};

struct		s_list
{
	int		value;
	t_list	*next;
	t_list	*end;

	void (*f[FTNBR])(t_list *list);
};

void	ft_swap(t_list *list)
{
	int tmp;

	tmp = list->value;
	list->value = list->next->value;
	list->next->value = tmp;
}

void	new(t_list *head, int value)
{
	t_list	*p;

	p = (t_list *)malloc(sizeof(t_list));
	p->value = value;
	p->next = NULL;
	p->end = NULL;
	p->f[SWAP] = ft_swap;
	if (!head)
		head = p;
}

int		main(int argc, char **argv)
{
	// add chunk for each argv
	t_list	*stack;

	stack = NULL;
	while (argc > 1 || !ft_strcmp(argv[argc], "0"))
		new(stack, ft_atoi(argv[argc--]));
	return (0);
}
