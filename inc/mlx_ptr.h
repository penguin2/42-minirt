/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_ptr.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:30:40 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/02 20:44:46 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_PTR_H
# define MLX_PTR_H

# include "image.h"
# include "mlx_hook_helper.h"
# include "scene.h"
# include <stdbool.h>

# define COMMAND_MODE_SPACE_STR "	"
# define MLX_BUFFER_SIZE 30

typedef enum e_mlx_mode
{
	MLX_MODE_NORMAL,
	MLX_MODE_COMMAND,
}	t_mlx_mode;

typedef int	(*t_fn_exec_command)(char **);

typedef struct s_mlx_ptr{
	void				*ptr;
	void				*wdw_ptr;
	bool				is_to_update;
	bool				is_button_left_pressed;
	bool				is_shift_pressed;
	t_image				*image;
	t_scene				*scene;
	t_mlx_hook_helper	mlx_hook_helper;
	t_mlx_mode			mode;
	char				buffer[MLX_BUFFER_SIZE];
}	t_mlx_ptr;

int	mlx_ptr_init(t_mlx_ptr *mlx_ptr, t_image *image, t_scene *scene);
int	mlx_ptr_loop_hook_fn(t_mlx_ptr *mlx_ptr);
int	mlx_ptr_main(t_scene *scene);
int	mlx_ptr_set_hook(t_mlx_ptr *mlx_ptr);

int	mlx_ptr_hook_key_press(int keycode, t_mlx_ptr *mlx_ptr);
int	mlx_ptr_hook_key_release(int keycode, t_mlx_ptr *mlx_ptr);
int	mlx_ptr_hook_button_press(int button, int x, int y, t_mlx_ptr *mlx_ptr);
int	mlx_ptr_hook_button_release(int button, int x, int y, t_mlx_ptr *mlx_ptr);
int	mlx_ptr_hook_motion_notify(int x, int y, t_mlx_ptr *mlx_ptr);
int	mlx_ptr_hook_expose(t_mlx_ptr *mlx_ptr);
int	mlx_ptr_hook_destroy_notify(t_mlx_ptr *mlx_ptr);

// buffer utils
int	write_buffer(char *buffer, int c, size_t buffer_max_size);
int	remove_buffer(char *buffer);
int	flush_buffer(char *buffer);

#endif
