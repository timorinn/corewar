cmake_minimum_required(VERSION 3.14)
project(corewar)

set(CMAKE_C_STANDARD 90)

include_directories(libft)
include_directories(ft_printf)
include_directories(vm)
add_executable(corewar main.c vm/vm_no_print_map.c vm/vm_make_start_list_cursor.c vm/vm_lstdel_cursor.c vm/vm_rewrite_map.c vm/vm_init_cycle.c vm/vm_arena.c vm/op_all_fork.c vm/vm_op_aff.c vm/vm_op_live.c vm/vm_get_args.c vm/vm_arena.c vm/vm_print_map.c vm/vm_print_map_single.c vm/vm_print_players.c vm/vm_op_lld.c vm/vm_op_lfork.c vm/vm_op_fork.c vm/vm_valid_input.c vm/vm_init_input.c vm/vm_init_player.c vm/vm_check_cursor.c vm/vm_error.c vm/vm_print_cursor.c vm/vm_do_cycle.c vm/vm_init_t_dir.c vm/vm_init_t_ind.c vm/vm_init_args.c vm/vm_dir_or_ind.c vm/vm_move.c vm/vm_op_ld.c vm/vm_op_zjmp.c vm/vm_op_st.c vm/vm_op_add.c vm/vm_op_add.c vm/vm_op_sub.c vm/vm_op_and.c vm/vm_get_args.c vm/vm_unfold_indirects.c vm/vm_validate_args.c vm/vm_op_sti.c vm/vm_op_or.c vm/vm_op_xor.c vm/op_bitwise.c vm/vm_op_ldi.c vm/op_load.c vm/op_load_i.c vm/vm_op_lldi.c vm/op_add_sub.c vm/vm_print_log.c vm/vm_make_player_params.c vm/vm_init_player.h vm/vm_player_lst.c vm/vm_print_map.h)
target_compile_options(corewar PUBLIC -o3)
add_subdirectory(libft)
target_link_libraries(corewar libft ncurses)
add_subdirectory(ft_printf)
target_link_libraries(corewar ft_printf)