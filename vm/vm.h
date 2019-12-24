/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2019/12/24 18:23:31 by bford            ###   ########.fr       */
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
# include <fcntl.h>
# include <stdint.h>
# include <ncurses.h>

#include <stdbool.h>


# include <stdio.h>

# define HEX "0123456789abcdef"

static int			g_operation[16] = {10, 5, 5, 10, 10, 6, 6, 6, 20, 25, 25, 800/* 800 */, 10, 50, 1000, 2};

//
//typedef struct {
//	unsigned int	magic;
//	char			prog_name[PROG_NAME_LENGTH + 1];
//	unsigned int	prog_size;
//	char			comment[COMMENT_LENGTH + 1];
//}					t_header;
//

typedef struct		s_player
{
	int				num;
	char			*name;
	char			*comment;
	unsigned char	*code;
	int				size;
	struct s_player	*next;
}					t_player;

typedef struct {
	int				num;
	int				play_num;
	int				size;
	int				position;
	int				operation;
	int				cooldown;
	int				registr[REG_NUMBER + 1];
	int				carry;
	int				live;
}	t_cursor;

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

int					ft_valid_input(int argc, char **argv);

t_player			*ft_init_input(int argc, char **argv, int valid, int dump);
int					ft_init_player(char **argv, int *i, t_player **player, int *numbers);
t_player			*ft_lstnew_player(int num);
int					ft_lstdel_player(t_player *player);
int					ft_lstlen_player(t_player *player);
int					ft_error(int num, char *s);
int					ft_map(int dump, t_player *player, int v);
int					ft_print_map(uint8_t map[MEM_SIZE][4], t_cursor *car, t_player *player);
int					ft_print_players(t_player *player);
int					ft_print_map_single(uint8_t map[MEM_SIZE][4]);
t_cursor			*ft_make_array_careta(t_player *player, uint8_t map[MEM_SIZE][4]);
int					ft_print_careta(t_cursor *careta);

int					ft_do_cycle(uint8_t map[MEM_SIZE][4], t_cursor **car, int cycle);

t_dir				ft_init_t_dir(uint8_t map[MEM_SIZE][4],
		int position, uint8_t dir_size);
void				ft_init_t_ind(uint8_t map[MEM_SIZE][4],
		int position, t_ind *ind);
void				ft_init_args(uint8_t map[MEM_SIZE][4],
		int position, uint8_t args[4]);

int					vm_get_args(uint8_t map[MEM_SIZE][4],
		t_cursor *car, t_args *args);
void				vm_unfold_all(uint8_t map[MEM_SIZE][4], t_cursor *car,
						  t_args *args, bool is_idx_needed);

int					ft_dir_or_ind(unsigned int arg, int tdir);
int					ft_move(uint8_t args[4], char *valid, int dir);


bool				op_bitwise(uint8_t map[MEM_SIZE][4], t_cursor *car,
							   int32_t (*operation)(int32_t, int32_t));
bool				op_load(uint8_t map[MEM_SIZE][4], t_cursor *car, bool is_idx_needed);
bool				op_load_i(uint8_t map[MEM_SIZE][4], t_cursor *car, bool ll);


int					vm_op_live(uint8_t map[MEM_SIZE][4], t_cursor *car, int cycle);
bool				vm_op_ld(uint8_t map[MEM_SIZE][4], t_cursor *car);
bool				vm_op_lld(uint8_t map[MEM_SIZE][4], t_cursor *car);
bool				vm_op_ldi(uint8_t map[MEM_SIZE][4], t_cursor *car);
bool				vm_op_lldi(uint8_t map[MEM_SIZE][4], t_cursor *car);
int					vm_op_zjmp(uint8_t map[MEM_SIZE][4], t_cursor *car);
bool				vm_op_st(uint8_t map[MEM_SIZE][4], t_cursor *car);
bool				vm_op_sti(uint8_t map[MEM_SIZE][4], t_cursor *car);
bool				vm_op_add(uint8_t map[MEM_SIZE][4], t_cursor *car);
bool				vm_op_sub(uint8_t map[MEM_SIZE][4], t_cursor *car);
bool				vm_op_all_fork(uint8_t map[MEM_SIZE][4], t_cursor *car,
					t_cursor **allcar, int32_t (*operation)(int32_t, int32_t));
bool				vm_op_fork(uint8_t map[MEM_SIZE][4], t_cursor *car, t_cursor **allcar);
bool				vm_op_lfork(uint8_t map[MEM_SIZE][4], t_cursor *car, t_cursor **allcar);
bool				vm_op_and(uint8_t map[MEM_SIZE][4], t_cursor *car);
bool				vm_op_or(uint8_t map[MEM_SIZE][4], t_cursor *car);
bool				vm_op_xor(uint8_t map[MEM_SIZE][4], t_cursor *car);
bool				vm_op_aff(uint8_t map[MEM_SIZE][4], t_cursor *car);

bool				vm_validate_args(t_args args, char *validate);


void	ft_rewrite_map(uint8_t map[MEM_SIZE][4],
					   t_cursor *car, uint32_t reg, int adress);


#endif
