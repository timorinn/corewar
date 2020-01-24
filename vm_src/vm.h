/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2020/01/24 13:45:39 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <fcntl.h>
# include <stdint.h>
# include <ncurses.h>
# include <dirent.h>
# include <stdbool.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "vm_defines.h"
# include "vm_structs.h"
# include "vm_init_player.h"

static int		g_operation[16] = {
	10, 5, 5, 10, 10, 6, 6, 6,
	20, 25, 25, 800, 10, 50, 1000, 2
};

void				vm_valid_input(int argc, char **argv, t_flags flags);
t_player			*vm_init_input(int argc, char **argv, t_flags flags);
void				vm_init_player(char **argv, int *i, t_player **player,
									int8_t *numbers);
t_player			*vm_lstnew_player(int num);
int					vm_lstdel_player(t_player *player);
int8_t				vm_lstlen_player(t_player *player);
int8_t				vm_error(int8_t num, const char *s);
void				vm_arena(t_flags flags, t_player *player);
void				vm_print_map(uint8_t map[MEM_SIZE][4], t_cursor **car,
								t_player *player, t_cycle *cycle);
void				vm_no_print_map(uint8_t map[MEM_SIZE][4], t_cursor **cur,
									t_player *player, t_cycle *cycle);
int					vm_print_players(t_player *player);
t_cursor			*vm_make_start_list_cursor(t_player *player,
												uint8_t map[MEM_SIZE][4]);
int					vm_print_cursor(t_cursor *careta, t_cycle cycle);
int					vm_do_cycle(uint8_t map[MEM_SIZE][4],
								t_cursor **car, t_cycle *cycle);
void				vm_init_cycle(t_cycle *cycle,
								int player_size, t_flags flags);

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
void				vm_move(t_cursor *cur, const uint8_t args[4],
							const char *valid, int dir);

bool				op_bitwise(uint8_t map[MEM_SIZE][4],
								int32_t (*operation)(int32_t, int32_t),
								t_cycle *cycle);
bool				op_add_sub(uint8_t map[MEM_SIZE][4],
								int32_t (*operation)(int32_t, int32_t),
								t_cycle *cycle);
bool				op_load(uint8_t map[MEM_SIZE][4], bool is_idx_needed,
							t_cycle *cycle);
bool				op_load_i(uint8_t map[MEM_SIZE][4], bool ll,
							t_cycle *cycle);
bool				op_all_fork(uint8_t map[MEM_SIZE][4],
								t_cycle *cycle, t_cursor **cur,
								int32_t (*operation)(int32_t, int32_t));

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
bool				vm_op_fork(uint8_t map[MEM_SIZE][4], t_cursor **allcar,
								t_cycle *cycle);
bool				vm_op_lfork(uint8_t map[MEM_SIZE][4], t_cursor **allcar,
								t_cycle *cycle);
bool				vm_op_and(uint8_t map[MEM_SIZE][4], t_cycle *cycle);
bool				vm_op_or(uint8_t map[MEM_SIZE][4], t_cycle *cycle);
bool				vm_op_xor(uint8_t map[MEM_SIZE][4], t_cycle *cycle);
bool				vm_op_aff(uint8_t map[MEM_SIZE][4], t_cycle *cycle);

bool				vm_validate_args(t_args args, char const *validate,
									uint8_t max_args);
void				vm_rewrite_map(uint8_t map[MEM_SIZE][4],
									t_cursor *car, uint32_t reg, int adress);
int					vm_check_cursor(uint8_t map[MEM_SIZE][4],
									t_cursor **cur, t_cycle *cycle);
void				vm_lstdel_cursor(t_cursor *cursor);
void				vm_print_log_op(char *op, t_cycle *cycle);
void				vm_print_log_args(t_args *args, uint8_t max_args);

#endif
