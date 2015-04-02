#include "stack.h"
#include "tree.h"

t_tree		*new_tree(void)
{
	t_tree	*tmp;

	if (!(tmp = (t_tree *)malloc(sizeof(t_tree))))
		die (-1);
	tmp->s = new_stack(NULL);
	tmp->next = NULL;
	tmp->branch = NULL;
	return (tmp);
}

t_tree	*make_branch(int depth)
{

	extern void		(*t[11])(void);
	t_tree *new;
	t_tree *p;

	new = new_tree();
	p = new;
	int i = 0;
	static int j;
	while (i < 12)
	{
		j += 1;
		if (j < depth)
			new->branch = make_branch(depth);
		j -= 1;
		new->next = new_tree();
		new->s->p = t[i];
		new = new->next;
		i += 1;
	}
	return (p);
}
