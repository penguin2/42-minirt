/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_fn_save_scene.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:56:38 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/01 14:06:23 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "define.h"
#include "mlx_hook_helper.h"
#include "mlx_ptr.h"
#include "generator.h"
#include <X11/keysym.h>

void	hook_fn_save_scene(t_mlx_ptr *mlx_ptr, int keycode)
{
	t_scene	*scene;

	scene = mlx_ptr->scene;
	if (keycode == XK_F1)
		json_generator_from_scene(scene);
	else
		return ;
}
