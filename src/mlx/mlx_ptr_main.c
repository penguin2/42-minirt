/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_ptr_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:47:38 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/23 17:28:50 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_ptr.h"
#include "scene.h"
#include "define.h"
#include <mlx.h>

int	mlx_ptr_main(t_scene *scene)
{
	t_image		image;
	t_mlx_ptr	mlx_ptr;

	if (image_init(&image, &scene->camera) == ERROR
		|| mlx_ptr_init(&mlx_ptr, &image, scene) == ERROR
		|| mlx_ptr_set_hook(&mlx_ptr) == ERROR)
		return (ERROR);
	mlx_loop_hook(mlx_ptr.ptr, mlx_ptr_loop_hook_fn, &mlx_ptr);
	mlx_loop(mlx_ptr.ptr);
	return (SUCCESS);
}
