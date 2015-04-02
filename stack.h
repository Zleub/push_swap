#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_stack	t_stack;

struct					s_stack
{
	void				(*p)(void);
	t_stack				*next;
};

t_stack		*new_stack(void(*p)(void));
void		print_stack(t_stack *head);
void		push_stack(t_stack **head, t_stack *elem);
void	die(int val);
