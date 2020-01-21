//
// Created by Katharine Psylocke on 21/01/2020.
//

#ifndef VM_INIT_PLAYER_H
#define VM_INIT_PLAYER_H

#include "vm.h"

int8_t	make_player_name(t_player *player, char *name);
int8_t	make_player_comment(t_player *player, char *comment);
int8_t	make_player_code(t_player *player, char *code, int code_size);
int8_t	make_code_size(int *code_size, char *buf);

#endif
