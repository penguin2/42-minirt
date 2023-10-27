/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook_helper.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:13:25 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/27 10:19:31 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_HOOK_HELPER_H
# define MLX_HOOK_HELPER_H

# define HOOK_KEY_PRESS_CNT			(15)
# define HOOK_KP_ESCAPE				(0)
# define HOOK_KP_LEFT				(1)
# define HOOK_KP_RIGHT				(2)
# define HOOK_KP_UP					(3)
# define HOOK_KP_DOWN				(4)
# define HOOK_KP_Q					(5)
# define HOOK_KP_E					(6)
# define HOOK_KP_W					(7)
# define HOOK_KP_A					(8)
# define HOOK_KP_S					(9)
# define HOOK_KP_D					(10)
# define HOOK_KP_SPACE				(11)
# define HOOK_KP_SHIFT_L			(12)
# define HOOK_KP_SHIFT_R			(13)
# define HOOK_KP_Z					(14)

# define HOOK_KEY_RELEASE_CNT		(2)
# define HOOK_KR_SHIFT_L			(0)
# define HOOK_KR_SHIFT_R			(1)

# define HOOK_BUTTON_PRESS_CNT		(1)
# define HOOK_BP_BUTTON_LEFT		(0)

# define HOOK_BUTTON_RELEASE_CNT	(1)
# define HOOK_BR_BUTTON_LEFT		(0)

# define BUTTON_LEFT_X				(1)

typedef struct s_mlx_ptr	t_mlx_ptr;

typedef void				(*t_fn_key_hook)(t_mlx_ptr*, int);
typedef void				(*t_fn_button_hook)(t_mlx_ptr*, int, int);

typedef struct s_mlx_hook_helper{
	int					key_press[HOOK_KEY_PRESS_CNT];
	t_fn_key_hook		key_press_fn[HOOK_KEY_PRESS_CNT];
	int					key_release[HOOK_KEY_RELEASE_CNT];
	t_fn_key_hook		key_release_fn[HOOK_KEY_RELEASE_CNT];
	int					button_press[HOOK_BUTTON_PRESS_CNT];
	t_fn_button_hook	button_press_fn[HOOK_BUTTON_PRESS_CNT];
	int					button_release[HOOK_BUTTON_RELEASE_CNT];
	t_fn_button_hook	button_release_fn[HOOK_BUTTON_RELEASE_CNT];
}						t_mlx_hook_helper;

int		mlx_hook_helper_init(t_mlx_hook_helper *mlx_hook_helper);
void	mlx_hook_helper_init_key_press(t_mlx_hook_helper *mlx_hook_helper);
void	mlx_hook_helper_init_key_release(t_mlx_hook_helper *mlx_hook_helper);
void	mlx_hook_helper_init_button_press(t_mlx_hook_helper *mlx_hook_helper);
void	mlx_hook_helper_init_button_release(t_mlx_hook_helper *mlx_hook_helper);

//hook_fn: key_press
void	hook_fn_exit(t_mlx_ptr *mlx_ptr, int keycode);
void	hook_fn_rotate_camera(t_mlx_ptr *mlx_ptr, int keycode);
void	hook_fn_move_camera(t_mlx_ptr *mlx_ptr, int keycode);
void	hook_fn_zoom_camera(t_mlx_ptr *mlx_ptr, int keycode);
void	hook_fn_set_shift_on(t_mlx_ptr *mlx_ptr, int keycode);

//hook_fn: key_release
void	hook_fn_set_shift_off(t_mlx_ptr *mlx_ptr, int keycode);

//hook_fn: button_press 
void	hook_fn_set_button_left_on(t_mlx_ptr *mlx_ptr, int x, int y);

//hook_fn: button_release 
void	hook_fn_set_button_left_off(t_mlx_ptr *mlx_ptr, int x, int y);

#endif
