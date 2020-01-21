/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2020/01/17 14:53:59 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# define IND_SIZE				2
# define REG_SIZE				4
# define DIR_SIZE				REG_SIZE

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

# define MAX_ARGS_NUMBER		4
# define MAX_PLAYERS			4
# define MEM_SIZE				(4 * 1024)
# define IDX_MOD				(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

# define COMMENT_CHAR			'#'
# define LABEL_CHAR				':'
# define DIRECT_CHAR			'%'
# define SEPARATOR_CHAR			','

# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING		".name"
# define COMMENT_CMD_STRING		".comment"

# define REG_NUMBER				16

# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA			50
# define NBR_LIVE				21
# define MAX_CHECKS				10

# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

# define GRANICA "************************************************************\
******************************************************************************\
******************************************************************************\
**************************************\n"

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

# include <fcntl.h>
# include <stdint.h>
# include <ncurses.h>
# include <dirent.h>

#include <stdbool.h>


# include <stdio.h>

# define HEX "0123456789abcdef"

static int			g_operation[16] = {10, 5, 5, 10, 10, 6, 6, 6, 20, 25, 25, 800/* 800 */, 10, 50, 1000, 2};

typedef struct		s_player
{
	int8_t			num;
	char			*name;
	char			*comment;
	unsigned char	*code;
	int32_t			size;
	struct s_player	*next;
}					t_player;

typedef struct		s_cursor {
	int				num;
	int				play_num;
	int				position;
	int				operation;
	int				cooldown;
	int				registr[REG_NUMBER + 1];
	int				carry;
	int				live;
	struct s_cursor	*next;
}					t_cursor;

typedef union {
	int8_t bytes[4];
	int32_t	data;
}	t_dir;

typedef union {
	int8_t	bytes[2];
	int16_t	data;
}	t_ind;

typedef struct {
	uint8_t		types[4];
	int32_t		nums[4];
	int32_t 	nums_unfolded[4];
//	int32_t		offsets[4];
	int32_t 	offset;
	uint8_t 	dir_size;
}	t_args;

typedef struct {
	t_cursor	*now_cur;
//	int32_t		new_cur_num;
	int32_t		cycle_num;
	int32_t		dump;
	bool		log;
	int32_t		cycles_to_die;
	int32_t		waiting_die;
	int32_t		last_live[MAX_PLAYERS];
	int32_t		lives_in_current_period[MAX_PLAYERS];
	int32_t		lives_in_current_period_all;
	int32_t		cur_len;
	int32_t		v;
	int32_t		checks;
	int32_t		winner_y;
	int32_t		winner_num;
	int64_t 	processes_qty;
}	t_cycle;

typedef struct {
	int32_t	dump;
	bool	log;
	int8_t	offset;
}	t_flags;



# include "vm_init_player.h"



int8_t				vm_valid_input(int argc, char **argv);

t_player			*vm_init_input(int argc, char **argv, int8_t valid,
		t_flags flags);
int8_t				vm_init_player(char **argv, int *i, t_player **player,
		int8_t *numbers);
t_player			*vm_lstnew_player(int num);
int					vm_lstdel_player(t_player *player);
int8_t				vm_lstlen_player(t_player *player);
int8_t				vm_error(int8_t num, char *s);
void				vm_arena(t_flags flags, t_player *player, int v);
int					vm_print_map(uint8_t map[MEM_SIZE][4], t_cursor **car,
								t_player *player, t_cycle *cycle);
void				vm_no_print_map(uint8_t map[MEM_SIZE][4], t_cursor **cur,
							   t_player *player, t_cycle *cycle);
int					vm_print_players(t_player *player);
int					vm_print_map_single(uint8_t map[MEM_SIZE][4]);
t_cursor			*vm_make_start_list_cursor(t_player *player, uint8_t map[MEM_SIZE][4]);
int					vm_print_cursor(t_cursor *careta, t_cycle cycle);
int					vm_do_cycle(uint8_t map[MEM_SIZE][4], t_cursor **car, t_cycle *cycle);
void				vm_init_cycle(t_cycle *cycle, int player_size, t_flags flags, int v);

t_dir				vm_init_t_dir(uint8_t map[MEM_SIZE][4],
		int position, uint8_t dir_size);
void				vm_init_t_ind(uint8_t map[MEM_SIZE][4],
		int position, t_ind *ind);
void				vm_init_args(uint8_t map[MEM_SIZE][4],
		int16_t position, uint8_t args[4]);
int					vm_get_args(uint8_t map[MEM_SIZE][4],
								t_cursor *car, t_args *args);
void				vm_unfold_all(uint8_t map[MEM_SIZE][4], t_cursor *car,
						  			t_args *args, bool is_idx_needed);

int8_t				vm_dir_or_ind(unsigned int arg, int8_t tdir);
void				vm_move(t_cursor *cur, uint8_t args[4], char *valid, int dir);


bool				op_bitwise(uint8_t map[MEM_SIZE][4], int32_t (*operation)(int32_t, int32_t),
								t_cycle *cycle);
bool				op_add_sub(uint8_t map[MEM_SIZE][4],
							   int32_t (*operation)(int32_t, int32_t), t_cycle *cycle);
bool				op_load(uint8_t map[MEM_SIZE][4], bool is_idx_needed, t_cycle *cycle);
bool				op_load_i(uint8_t map[MEM_SIZE][4], bool ll, t_cycle *cycle);
bool				op_all_fork(uint8_t map[MEM_SIZE][4], t_cycle *cycle,
								t_cursor **cur, int32_t (*operation)(int32_t, int32_t));

int					vm_op_live(uint8_t map[MEM_SIZE][4], t_cycle *cycle);
bool				vm_op_ld(uint8_t map[MEM_SIZE][4], t_cycle *cycle);
bool				vm_op_lld(uint8_t map[MEM_SIZE][4], t_cycle *cycle);
bool				vm_op_ldi(uint8_t map[MEM_SIZE][4], t_cycle *cycle);
bool				vm_op_lldi(uint8_t map[MEM_SIZE][4], t_cycle *cycle);
int					vm_op_zjmp(uint8_t map[MEM_SIZE][4], t_cycle *cycle);
bool				vm_op_st(uint8_t map[MEM_SIZE][4], t_cycle *cycle);
bool				vm_op_sti(uint8_t map[MEM_SIZE][4], t_cycle *cycle);
bool				vm_op_add(uint8_t map[MEM_SIZE][4], t_cycle *cycle);
bool				vm_op_sub(uint8_t map[MEM_SIZE][4], t_cycle *cycle);
bool				vm_op_fork(uint8_t map[MEM_SIZE][4], t_cursor **allcar, t_cycle *cycle);
bool				vm_op_lfork(uint8_t map[MEM_SIZE][4], t_cursor **allcar, t_cycle *cycle);
bool				vm_op_and(uint8_t map[MEM_SIZE][4], t_cycle *cycle);
bool				vm_op_or(uint8_t map[MEM_SIZE][4], t_cycle *cycle);
bool				vm_op_xor(uint8_t map[MEM_SIZE][4], t_cycle *cycle);
bool				vm_op_aff(uint8_t map[MEM_SIZE][4], t_cycle *cycle);

bool				vm_validate_args(t_args args, char const *validate, uint8_t max_args);


void				vm_rewrite_map(uint8_t map[MEM_SIZE][4],
					   t_cursor *car, uint32_t reg, int adress);
					   
int					vm_check_cursor(uint8_t map[MEM_SIZE][4],
									t_cursor **cur, t_cycle *cycle);
void				vm_lstdel_cursor(t_cursor *cursor);

void				vm_print_log_op(char *op, t_cycle *cycle);
void				vm_print_log_args(t_args *args, uint8_t max_args);

#endif
