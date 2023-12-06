/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_command_mode.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:44:14 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/06 20:43:45 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_COMMAND_MODE_H
# define MLX_COMMAND_MODE_H

# include "mlx_ptr.h"
# include <stddef.h>

# define MLX_BUFFER_SPACE_STR " "
# define MLX_COMMAND_LINE_COLOR 16776960
# define MLX_COMMAND_LINE_ERROR_COLOR 16711680
# define MLX_COMMAND_LINE_SUCCESS_COLOR 65280
# define MLX_COMMAND_LINE_STD_COLOR 16777215

typedef int	(*t_fn_mlx_command)(t_mlx_ptr *mlx_ptr, char **strings);

// mlx hook helper init
void	mlx_hook_helper_init_key_press_cmd_mode(t_hook *hooks_kp_cmd);

// hook fn cmd mode
void	hook_fn_exit_cmd_mode(t_mlx_ptr *mlx_ptr, int keycode);
void	hook_fn_delete(t_mlx_ptr *mlx_ptr, int keycode);
void	hook_fn_return(t_mlx_ptr *mlx_ptr, int keycode);
void	hook_fn_input_alphabet(t_mlx_ptr *mlx_ptr, int keycode);
void	hook_fn_input_digit(t_mlx_ptr *mlx_ptr, int keycode);
void	hook_fn_input_sp_char(t_mlx_ptr *mlx_ptr, int keycode);

// utils
void	exit_cmd_mode(t_mlx_ptr *mlx_ptr);
void	reset_command_line_image(t_mlx_ptr *mlx_ptr);
int		mlx_string_put_cmd_mode(t_mlx_ptr *mlx_ptr, char *str, int color);
int		mlx_error_message_put_cmd_mode(t_mlx_ptr *mlx_ptr, char *str);
int		mlx_success_message_put_cmd_mode(t_mlx_ptr *mlx_ptr, char *str);

// buffer utils
int		mlx_buffer_flush(char *buffer);
int		mlx_buffer_write(char *buffer, int c);
int		mlx_buffer_remove(char *buffer);
int		mlx_buffer_parse(const char *buffer);

// command line parse
int		parse_mlx_command_line(t_mlx_ptr *mlx_ptr, char **strings);

int		mlx_save_parser(t_mlx_ptr *mlx_ptr, char **strings);
int		mlx_exit_parser(t_mlx_ptr *mlx_ptr, char **strings);
int		mlx_dump_parser(t_mlx_ptr *mlx_ptr, char **strings);

#endif
