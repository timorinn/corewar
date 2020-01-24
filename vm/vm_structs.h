/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 12:48:31 by bford             #+#    #+#             */
/*   Updated: 2020/01/24 12:52:17 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_STRUCTS_H
# define VM_STRUCTS_H

typedef	union {
	uint8_t		bytes[4];
	uint32_t	all;
}	t_magic;

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
	int8_t			bytes[4];
	int32_t			data;
}	t_dir;

typedef union {
	int8_t			bytes[2];
	int16_t			data;
}	t_ind;

typedef struct {
	uint8_t			types[4];
	int32_t			nums[4];
	int32_t			nums_unfolded[4];
	int32_t			offset;
	uint8_t			dir_size;
}	t_args;

typedef struct {
	t_cursor		*now_cur;
	int32_t			cycle_num;
	int32_t			dump;
	bool			log;
	int32_t			cycles_to_die;
	int32_t			waiting_die;
	int32_t			last_live[MAX_PLAYERS];
	int32_t			lives_in_current_period[MAX_PLAYERS];
	int32_t			lives_in_current_period_all;
	int32_t			cur_len;
	int32_t			v;
	int32_t			checks;
	int32_t			winner_y;
	int32_t			winner_num;
	int64_t			processes_qty;
}	t_cycle;

typedef struct {
	int32_t			dump;
	bool			log;
	int8_t			offset;
	bool			v;
}	t_flags;

#endif
