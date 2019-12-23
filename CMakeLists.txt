cmake_minimum_required(VERSION 3.14)
project(corewar)

set(CMAKE_C_STANDARD 90)

include_directories(libft)
include_directories(vm)
add_executable(corewar main.c vm/ft_live.c vm/vm_get_args.c vm/ft_print_map_single.c vm/ft_print_players.c vm/ft_lld.c vm/ft_lfork.c vm/ft_fork.c vm/ft_valid_input.c vm/ft_init_input.c vm/ft_init_player.c vm/ft_lstnew_player.c vm/ft_lstlen_player.c vm/ft_lstdel_player.c vm/ft_error.c vm/ft_map.c vm/ft_print_map.c vm/ft_make_array_careta.c vm/ft_print_careta.c vm/ft_do_cycle.c vm/ft_init_t_dir.c vm/ft_init_t_ind.c vm/ft_init_args.c vm/ft_dir_or_ind.c vm/ft_move.c vm/ft_ld.c vm/ft_zjmp.c vm/ft_st.c vm/ft_add.c vm/ft_add.c vm/ft_sub.c vm/ft_and.c vm/vm_get_args.c vm/vm_unfold_all.c vm/vm_validate_args.c)
add_subdirectory(libft)
target_link_libraries(corewar libft ncurses)