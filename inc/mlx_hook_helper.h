/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook_helper.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:13:25 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/23 15:43:55 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_HOOK_HELPER_H
# define MLX_HOOK_HELPER_H

# include "scene.h"

# define HOOK_KEY_PRESS_CNT			(1)
# define HOOK_KP_ESCAPE				(0)

typedef struct s_mlx_hook_helper{
	int		key_press[HOOK_KEY_PRESS_CNT];
	void	(*key_press_fn[HOOK_KEY_PRESS_CNT])(t_scene *scene);
}			t_mlx_hook_helper;

int		mlx_hook_helper_init(t_mlx_hook_helper *mlx_hook_helper);
void	mlx_hook_helper_init_key_press(t_mlx_hook_helper *mlx_hook_helper);

//hook_fn
void	hook_fn_exit(t_scene *scene);

#endif
