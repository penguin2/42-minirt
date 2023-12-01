/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook_helper.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:13:25 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/01 14:06:55 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_HOOK_HELPER_H
# define MLX_HOOK_HELPER_H

# define HOOK_KEY_PRESS_CNT			(16)
# define HOOK_KEY_RELEASE_CNT		(2)
# define HOOK_BUTTON_PRESS_CNT		(1)
# define HOOK_BUTTON_RELEASE_CNT	(1)

# define BUTTON_LEFT_X				(1)

typedef struct s_mlx_ptr	t_mlx_ptr;

typedef void				(*t_fn_key_hook)(t_mlx_ptr*, int);
typedef void				(*t_fn_button_hook)(t_mlx_ptr*, int, int);

typedef struct s_hook{
	int		identifier;
	void	*handler;
}	t_hook;

typedef struct s_mlx_hook_helper{
	t_hook	hooks_key_press[HOOK_KEY_PRESS_CNT];
	t_hook	hooks_key_release[HOOK_KEY_RELEASE_CNT];
	t_hook	hooks_button_press[HOOK_BUTTON_PRESS_CNT];
	t_hook	hooks_button_release[HOOK_BUTTON_RELEASE_CNT];
}	t_mlx_hook_helper;

void	mlx_hook_helper_set_hook(t_hook *hook, int identifier, void *handler);
int		mlx_hook_helper_init(t_mlx_hook_helper *mlx_hook_helper);
void	mlx_hook_helper_init_key_press(t_hook *kp_hooks);
void	mlx_hook_helper_init_key_release(t_hook *kr_hooks);
void	mlx_hook_helper_init_button_press(t_hook *bp_hooks);
void	mlx_hook_helper_init_button_release(t_hook *br_hooks);

//hook_fn: key_press
void	hook_fn_exit(t_mlx_ptr *mlx_ptr, int keycode);
void	hook_fn_rotate_camera(t_mlx_ptr *mlx_ptr, int keycode);
void	hook_fn_move_camera(t_mlx_ptr *mlx_ptr, int keycode);
void	hook_fn_zoom_camera(t_mlx_ptr *mlx_ptr, int keycode);
void	hook_fn_set_shift_on(t_mlx_ptr *mlx_ptr, int keycode);
void	hook_fn_save_scene(t_mlx_ptr *mlx_ptr, int keycode);

//hook_fn: key_release
void	hook_fn_set_shift_off(t_mlx_ptr *mlx_ptr, int keycode);

//hook_fn: button_press 
void	hook_fn_set_button_left_on(t_mlx_ptr *mlx_ptr, int x, int y);

//hook_fn: button_release 
void	hook_fn_set_button_left_off(t_mlx_ptr *mlx_ptr, int x, int y);

#endif
