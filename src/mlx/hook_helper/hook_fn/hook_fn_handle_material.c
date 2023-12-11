/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_fn_handle_material.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:33:43 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/11 13:09:37 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "material_box.h"
#include "mlx_ptr.h"
#include "object.h"
#include "scene.h"
#include "utils.h"
#include <stdio.h>

void	hook_fn_handle_material(t_mlx_ptr *mlx_ptr, int x, int y)
{
	t_object	*closest;

	closest = object_get_closest(
			get_viewport_ray(&mlx_ptr->scene->camera, y, x),
			&mlx_ptr->scene->objects
			);
	if (closest == NULL)
		return ;
	if (material_box_swap(
			&closest->material_box, &closest->material) == SUCCESS)
		mlx_ptr->is_to_update = true;
}
