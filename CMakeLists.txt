cmake_minimum_required(VERSION 3.14)
project(corewar)

set(CMAKE_C_STANDARD 90)

include_directories(libft)
include_directories(vm)
add_executable(corewar main.c vm/vm_op_live.c vm/vm_get_args.c vm/ft_print_map_single.c vm/ft_print_players.c vm/vm_op_lld.c vm/vm_op_lfork.c vm/vm_op_fork.c vm/ft_valid_input.c vm/ft_init_input.c vm/ft_init_player.c vm/ft_lstnew_player.c vm/ft_lstlen_player.c vm/ft_lstdel_player.c vm/ft_error.c vm/ft_map.c vm/ft_print_map.c vm/ft_make_array_careta.c vm/ft_print_careta.c vm/ft_do_cycle.c vm/ft_init_t_dir.c vm/ft_init_t_ind.c vm/ft_init_args.c vm/ft_dir_or_ind.c vm/ft_move.c vm/vm_op_ld.c vm/vm_op_zjmp.c vm/vm_op_st.c vm/vm_op_add.c vm/vm_op_add.c vm/vm_op_sub.c vm/vm_op_and.c vm/vm_get_args.c vm/vm_unfold_indirects.c vm/vm_validate_args.c vm/vm_op_sti.c vm/vm_op_or.c vm/vm_op_xor.c vm/op_bitwise.c)
add_subdirectory(libft)
target_link_libraries(corewar libft ncurses)