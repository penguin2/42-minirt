/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook_helper.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:13:25 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/26 17:05:40 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_HOOK_HELPER_H
# define MLX_HOOK_HELPER_H

# define HOOK_KEY_PRESS_CNT			(9)
# define HOOK_KP_ESCAPE				(0)
# define HOOK_KP_LEFT				(1)
# define HOOK_KP_RIGHT				(2)
# define HOOK_KP_UP					(3)
# define HOOK_KP_DOWN				(4)
# define HOOK_KP_W					(5)
# define HOOK_KP_A					(6)
# define HOOK_KP_S					(7)
# define HOOK_KP_D					(8)

# define HOOK_BUTTON_PRESS_CNT		(1)
# define HOOK_BP_BUTTON_LEFT		(0)

# define HOOK_BUTTON_RELEASE_CNT	(1)
# define HOOK_BR_BUTTON_LEFT		(0)

# define BUTTON_LEFT_X				(1)

typedef void	(*t_key_press_fn)(void *_mlx_ptr, int keycode);
typedef void	(*t_button_press_fn)(void *_mlx_ptr, int x, int y);
typedef void	(*t_button_release_fn)(void *_mlx_ptr, int x, int y);

typedef struct s_mlx_hook_helper{
	int					key_press[HOOK_KEY_PRESS_CNT];
	t_key_press_fn		key_press_fn[HOOK_KEY_PRESS_CNT];
	int					button_press[HOOK_BUTTON_PRESS_CNT];
	t_button_press_fn	button_press_fn[HOOK_BUTTON_PRESS_CNT];
	int					button_release[HOOK_BUTTON_RELEASE_CNT];
	t_button_release_fn	button_release_fn[HOOK_BUTTON_RELEASE_CNT];
}						t_mlx_hook_helper;

int		mlx_hook_helper_init(t_mlx_hook_helper *mlx_hook_helper);
void	mlx_hook_helper_init_key_press(t_mlx_hook_helper *mlx_hook_helper);
void	mlx_hook_helper_init_button_press(t_mlx_hook_helper *mlx_hook_helper);
void	mlx_hook_helper_init_button_release(t_mlx_hook_helper *mlx_hook_helper);

//hook_fn: key_press
void	hook_fn_exit(void *_mlx_ptr, int keycode);
void	hook_fn_rotate_camera(void *_mlx_ptr, int keycode);
void	hook_fn_move_camera(void *_mlx_ptr, int keycode);

//hook_fn: button_press 
void	hook_fn_set_button_left_on(void *_mlx_ptr, int x, int y);

//hook_fn: button_release 
void	hook_fn_set_button_left_off(void *_mlx_ptr, int x, int y);

#endif
