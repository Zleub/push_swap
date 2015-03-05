/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 12:19:46 by adebray           #+#    #+#             */
/*   Updated: 2015/02/21 19:10:55 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <libft.h>
# include <ft_printf.h>
# include <errno.h>
# include <fcntl.h>
# include <op.h>

typedef struct s_corewar	t_corewar;

struct						s_corewar
{
	int						cycle_counter;
};

t_corewar					g_corewar;

void						die(int end);
void						draw(void);
void						update(int dt);
void						init_corewar(int player_nbr);

/*
** Debug
*/
# include <stdio.h>

# define OUT 1

void		print_clean_hexa(unsigned char c);

/*
** Memory
*/

typedef struct s_cell		t_cell;

struct						s_cell
{
	char					op;
	char					p; // IS A PROCESS HEAD ON THAT CELL
	char					c; // COLOR IF A PROCESS HAS WRITE
};

t_cell						g_memory[MEM_SIZE];

void						init_memory(int player_nbr);
void						dump_memory(void);

/*
** Player
*/

typedef struct s_heros		t_heros;

struct						s_heros
{
	header_t				head;
	char					*content;
	char					color;
	int						number;
};

t_heros						g_heros[MAX_PLAYERS];

int							invertbits(unsigned int i);
void						read_header(int, t_heros *);
void						read_heros(int fd, t_heros *heros);
void						get_heros(char *file);

typedef struct s_process	t_process;

struct						s_process
{
	int						delay;
	int						index;
	int						pc;
	char					registers[REG_NUMBER][REG_SIZE];
	int						carry;
	int						number;
	t_process				*next;
};

t_process					*g_process;

void						add_process(t_process *elem);
t_process					*new_process(t_process *elem);
void						print_process(t_process *head);
void						update_process(t_process *head);

/*
** Intruction
*/

typedef struct s_instruct	t_instruction;

struct						s_instruct
{
	int						type;
	int						size;
	char					*args;
};

t_instruction				g_instruction[MAX_ARGS_NUMBER];

t_op						get_op(t_process *p);
void						print_op(t_op op);
void						init_instruction(int max);
int							fill_instruction(t_process *p);
void						print_instruction();
void						print_instruction_decimal();
int			get_int_from_index(int index);

#endif
