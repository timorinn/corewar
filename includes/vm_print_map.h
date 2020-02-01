/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_print_map.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 12:57:02 by bford             #+#    #+#             */
/*   Updated: 2020/01/24 12:57:15 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_PRINT_MAP_H
# define VM_PRINT_MAP_H

# include "vm.h"

void	vm_init_colors(void);
void	vm_find_color(uint8_t map[MEM_SIZE][4], int position);

int		vm_print_winner_v(t_player *player, t_cycle *cycle);
void	print_border(void);
int		vm_print_contur(void);
int		vm_print_breakdown(int y);

int		vm_print_line(uint8_t map[MEM_SIZE][4], int i);
int		print_players(t_player *player, t_cycle *cycle, int y);
int		vm_print_backside(t_cycle *cycle, t_player *player);

#endif
