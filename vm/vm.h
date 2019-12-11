/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2019/12/11 16:03:25 by bford            ###   ########.fr       */
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
# define MEM_SIZE				(4*1024)
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

# include <stdio.h>

# define HEX "0123456789abcdef"

typedef struct		s_header
{
	unsigned int	magic;
	char			prog_name[PROG_NAME_LENGTH + 1];
	unsigned int	prog_size;
	char			comment[COMMENT_LENGTH + 1];
}					t_header;

typedef struct		s_player
{
	int				num;
	char			*name;
	char			*comment;
	unsigned char	*code;
	int				size;
	struct s_player	*next;
}					t_player;

typedef struct		caretaaa
{
	int				play_num;
	int				size;
	int				position;
	int				operation;
	int				cooldown;
	int				registr[16];
}					careta;

int					ft_valid_input(int argc, char **argv);

t_player			*ft_init_input(int argc, char **argv, int valid, int dump);
int					ft_init_player(char **argv, int *i, t_player **player, int *numbers);
t_player			*ft_lstnew_player(int num);
int					ft_lstdel_player(t_player *player);
int					ft_lstlen_player(t_player *player);
int					ft_error(int num, char *s);
int					ft_map(int dump, t_player *player, int v);
int					ft_print_hex(unsigned char c);
int					ft_print_map(unsigned char map[4096][4]);
careta				*ft_make_array_careta(t_player *player);
int					ft_print_careta(careta *careta);

int					ft_do_cycle(unsigned char map[4096][4], careta *car);

#endif
