/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_command_mode.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:44:14 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/13 14:21:03 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_COMMAND_MODE_H
# define MLX_COMMAND_MODE_H

# include "mlx_ptr.h"
# include "range.h"
# include "libcolor.h"
# include <stddef.h>

# define MLX_BUFFER_SPACE_STR " "
# define MLX_DUMP_END_STR "..."
# define MLX_BLANK_STR " \t\n"
# define COLOR_YELLOW 16776960
# define COLOR_RED 16711680
# define COLOR_GREEN 65280
# define COLOR_WHITE 16777215

# define CMD_HELP_TXT_FILE "./.help/help.txt"
# define CMD_HELP_DIR "./.help/"

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
void	reset_image(t_mlx_ptr *mlx_ptr, int height);
int		mlx_putcmd(t_mlx_ptr *mlx_ptr, char *str, int color, int return_val);

// buffer utils
int		mlx_buffer_flush(char *buffer);
int		mlx_buffer_write(char *buffer, int c);
int		mlx_buffer_remove(char *buffer);
int		mlx_buffer_parse(const char *buffer);

// command line parse
int		parse_mlx_command_line(t_mlx_ptr *mlx_ptr, char **strings);
void	mlx_file_dump(t_mlx_ptr *mlx_ptr, int fd);

int		mlx_save_parser(t_mlx_ptr *mlx_ptr, char **strings);
int		mlx_exit_parser(t_mlx_ptr *mlx_ptr, char **strings);
int		mlx_dump_parser(t_mlx_ptr *mlx_ptr, char **strings);
int		mlx_help_parser(t_mlx_ptr *mlx_ptr, char **strings);
int		mlx_mod_parser(t_mlx_ptr *mlx_ptr, char **strings);
int		mlx_del_parser(t_mlx_ptr *mlx_ptr, char **strings);

// modify

int		sphere_modify(t_mlx_ptr *mlx_ptr, const char *key, const char *value);
int		plane_modify(t_mlx_ptr *mlx_ptr, const char *key, const char *value);
int		cylinder_modify(t_mlx_ptr *mlx_ptr, const char *key, const char *value);
int		quadric_modify(t_mlx_ptr *mlx_ptr, const char *key, const char *value);
int		triangle_modify(t_mlx_ptr *mlx_ptr, const char *key, const char *value);
int		modify_double(
			t_mlx_ptr *mlx_ptr,
			double *dptr,
			const char *value,
			t_range range);
int		modify_double_half(t_mlx_ptr *mlx_ptr,
			double *dptr,
			const char *value,
			t_range range);
int		modify_vec3(
			t_mlx_ptr *mlx_ptr,
			t_vec3 *vec,
			const char *value,
			t_range range);
int		modify_vec3_unit(t_mlx_ptr *mlx_ptr,
			t_vec3 *vec,
			const char *value,
			t_range range);
int		modify_color(
			t_mlx_ptr *mlx_ptr,
			t_color *color,
			const char *value,
			t_range range);

#endif
