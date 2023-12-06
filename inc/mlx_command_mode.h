/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_command_mode.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:44:14 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/06 15:13:33 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_COMMAND_MODE_H
# define MLX_COMMAND_MODE_H

# include "mlx_ptr.h"
# include <stddef.h>

# define MLX_BUFFER_SPACE_STR "		"
# define MLX_COMMAND_LINE_COLOR 16776960

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

// buffer utils
int		mlx_buffer_flush(char *buffer);
int		mlx_buffer_write(char *buffer, int c);
int		mlx_buffer_remove(char *buffer);
int		mlx_buffer_parse(const char *buffer);

#endif
