/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsheev <nsheev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 17:41:33 by swedde            #+#    #+#             */
/*   Updated: 2020/01/31 20:56:48 by nsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "defines.h"
# include "asm_structs.h"
# include <stdarg.h>
# include <fcntl.h>

t_all				*set_def_gen(char *s);
int					write_int_to_file(t_all	*gen, unsigned int to_file);
void				do_exit(char **error_mes, t_all *gen);
int					reading(t_all *gen);
char				*char_to_string(char c);
t_token				*new_token(int type, char *content, t_point point);
void				push_tail_token(t_token **head, int type, char *con,
					t_point point);
void				lst_del_token(t_token *token);
void				print_point(t_point a);
void				lexical_analyz(t_all *gen);
void				print_token(t_token *token);
void				start_analyz(t_all *gen, t_token *token);
void				recording(t_all *gen);
void				set_size_code(t_all *gen, t_token *token);
int					write_short_to_file(t_all *gen, short to_file);
int					write_byte_to_file(t_all *gen, unsigned char c);
int					write_nam_com_to_file(t_all *gen, int len, int type);
void				print_token_type(int i);
t_token				*next_token(t_token *token, int i);
void				print_expexted_exit(t_all *gen, t_token *token,
					int i, ...);
int					is_equal_token_type(t_token *token, int i, ...);
void				parse_live(t_all *gen, t_token *token);
void				parse_ld(t_all *gen, t_token *token);
void				parse_st(t_all *gen, t_token *token);
void				parse_add(t_all *gen, t_token *token);
void				parse_and(t_all *gen, t_token *token);
void				parse_ldi(t_all *gen, t_token *token);
void				parse_sti(t_all *gen, t_token *token);
void				parse_aff(t_all *gen, t_token *token);
void				parse_op(t_all *gen, t_token *token);
void				parse_name(t_all *gen, t_token *token);
void				parse_comment(t_all *gen, t_token *token);
int					set_arg_and_size(t_all *gen, t_token *tmp, int move,
					int dir_size);
int					op_dir(t_all *gen, t_token *token, char op_c,
					int dir_size);
int					op_dirind_reg(t_all *gen, t_token *token, char op_c,
					int dir_size);
int					op_reg_regdirind_regdir(t_all *gen, t_token *token,
					char op_c, int dir_size);
int					op_reg_regind(t_all *gen, t_token *token, char op_c);
int					op_reg_reg_reg(t_all *gen, t_token *token, char op_c);
int					op_regdirind_regdirind_reg(t_all *gen, t_token *token,
					char op_c, int dir_size);
int					op_regdirind_regdir_reg(t_all *gen, t_token *token,
					char op_c, int dir_size);
int					op_reg(t_all *gen, t_token *token, char op_c);
void				get_op_code(t_all *gen, t_token *token);
int					is_delim(char c);
int					is_delop(char c);
int					is_char_labl(char c, char *pattern);
t_point				get_point(t_all *gen);
int					increment_point(t_all *gen);
void				find_name_comment(t_all *gen, int type, char *command);
int					is_label(t_all *gen);
int					find_label(t_all *gen);
int					is_op(t_all *gen);
char				*get_op_helper(char *s);
char				*get_op(char *s);
void				find_op(t_all *gen);
int					num_len(unsigned long num);
int					is_reg_arg(char *s);
void				find_reg_arg(t_all *gen);
int					is_dir_arg(char *s);
void				find_dir_arg(t_all *gen);
int					is_dir_labl_arg(char *s);
void				find_dir_labl_arg(t_all *gen);
int					is_ind_arg(char *s);
void				find_ind_arg(t_all *gen);
int					is_ind_labl_arg(char *s);
void				find_ind_labl_arg(t_all *gen);
void				find_nl_or_separ(t_all *gen);
void				reading_error(t_all *gen);
void				reading_helper_2(t_all *gen);
void				reading_helper(t_all *gen);
int					reading(t_all *gen);

#endif
