/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_ptr.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:30:40 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/23 14:57:39 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_PTR_H
# define MLX_PTR_H

# include "image.h"
# include "mlx_hook_helper.h"
# include "scene.h"
# include <stdbool.h>

typedef struct s_mlx_ptr{
	void				*ptr;
	void				*wdw_ptr;
	bool				is_to_update;
	t_image				*image;
	t_scene				*scene;
	t_mlx_hook_helper	mlx_hook_helper;
}	t_mlx_ptr;

int		mlx_ptr_init(t_mlx_ptr *mlx_ptr, t_image *image, t_scene *scene);
int		mlx_ptr_loop_hook_fn(t_mlx_ptr *mlx_ptr);
int		mlx_ptr_main(t_scene *scene);
void	mlx_ptr_set_hook(t_mlx_ptr *mlx_ptr);

int		mlx_ptr_key_press_hook(int keycode, t_mlx_ptr *mlx_ptr);

#endif
