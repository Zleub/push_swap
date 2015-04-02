#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_tree	t_tree;

struct					s_tree
{
	t_stack				*s;
	t_tree				*branch;
	t_tree				*next;
};

t_tree		*new_tree(void);
t_tree		*make_branch(int depth);
