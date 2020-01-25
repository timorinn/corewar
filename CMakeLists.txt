cmake_minimum_required(VERSION 3.14)
project(corewar)

set(CMAKE_C_STANDARD 90)

include_directories(libft)
include_directories(ft_printf)
include_directories(vm)
add_executable(corewar vm_src/vm.c vm_src/vm_no_print_map.c vm_src/vm_make_start_list_cursor.c vm_src/vm_lstdel_cursor.c vm_src/vm_rewrite_map.c vm_src/vm_init_cycle.c vm_src/vm_arena.c vm_src/op_all_fork.c vm_src/vm_op_aff.c vm_src/vm_op_live.c vm_src/vm_get_args.c vm_src/vm_arena.c vm_src/vm_print_map.c vm_src/vm_print_players.c vm_src/vm_op_lld.c vm_src/vm_op_lfork.c vm_src/vm_op_fork.c vm_src/vm_valid_input.c vm_src/vm_init_input.c vm_src/vm_init_player.c vm_src/vm_check_cursor.c vm_src/vm_error.c vm_src/vm_print_cursor.c vm_src/vm_do_cycle.c vm_src/vm_init_t_dir.c vm_src/vm_init_t_ind.c vm_src/vm_init_args.c vm_src/vm_dir_or_ind.c vm_src/vm_move.c vm_src/vm_op_ld.c vm_src/vm_op_zjmp.c vm_src/vm_op_st.c vm_src/vm_op_add.c vm_src/vm_op_add.c vm_src/vm_op_sub.c vm_src/vm_op_and.c vm_src/vm_get_args.c vm_src/vm_unfold_indirects.c vm_src/vm_validate_args.c vm_src/vm_op_sti.c vm_src/vm_op_or.c vm_src/vm_op_xor.c vm_src/op_bitwise.c vm_src/vm_op_ldi.c vm_src/op_load.c vm_src/op_load_i.c vm_src/vm_op_lldi.c vm_src/op_add_sub.c vm_src/vm_print_log.c vm_src/vm_make_player_params.c vm_src/vm_init_player.h vm_src/vm_player_lst.c vm_src/vm_print_map.h vm_src/vm_structs.h vm_src/vm_defines.h)
set(CMAKE_C_FLAGS "-o3 -march=native")

add_subdirectory(libft)
target_link_libraries(corewar libft ncurses)
add_subdirectory(ft_printf)
target_link_libraries(corewar ft_printf)