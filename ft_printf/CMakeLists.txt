cmake_minimum_required(VERSION 3.14)
project(ft_printf)

set(CMAKE_C_STANDARD 90)

include_directories(../libft)
#add_subdirectory(../libft ./libft)
find_library(../libft libft)
add_library(ft_printf STATIC ft_c.c ft_clearlist.c ft_d_func.c ft_d.c ft_f_func.c ft_f.c ft_lennbr_d.c ft_lennbr_u.c ft_lstnew_pf.c ft_many_write.c ft_nollist.c ft_o_func.c ft_o.c ft_p_func.c ft_p.c ft_postwork.c ft_power.c ft_pr.c ft_printf.c ft_putnbr_d.c ft_putnbr_f.c ft_putnbr_o.c ft_putnbr_second.c ft_putnbr_u.c ft_putnbr_x.c ft_s.c ft_s2.c ft_start_work.c ft_u_func.c ft_u.c ft_x_func.c ft_x.c)
add_dependencies(ft_printf ../libft/libft.a)
#target_link_libraries(ft_printf libft.a)
target_link_libraries(ft_printf libft)