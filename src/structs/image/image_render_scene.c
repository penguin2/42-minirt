/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_render_scene.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:12:18 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/18 11:23:15 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"
#include "image.h"
#include "libcolor.h"
#include "libvec3.h"
#include "ray.h"
#include <mlx.h>
#include <stddef.h>

static int	_get_ray_color(t_scene *scene, t_vec3 from, t_vec3 to);

void	image_render_scene(void *mlx, t_image *image, t_scene *scene)
{
	int				col_cnt;
	int				row_cnt;
	t_vec3			pixel;
	unsigned char	*addr;

	col_cnt = 0;
	row_cnt = 0;
	addr = image->addr;
	pixel = scene->camera.viewport.upper_left;
	while (row_cnt < image->height)
	{
		image_write_color(mlx, image, addr,
			_get_ray_color(scene, scene->camera.eye, pixel));
		++col_cnt;
		addr += image->byte_per_pixel;
		pixel = vec3_add(pixel, scene->camera.viewport.dw);
		if (col_cnt == image->width)
		{
			col_cnt = 0;
			++row_cnt;
			addr += image->size_line - image->width * image->byte_per_pixel;
			pixel = vec3_add(pixel, vec3_sub(scene->camera.viewport.dh,
						vec3_mul(scene->camera.viewport.dw, image->width)));
		}
	}
}

static int	_get_ray_color(t_scene *scene, t_vec3 from, t_vec3 to)
{
	const t_ray	ray = ray_create(from, vec3_sub(to, from));	
	t_color		color;
	t_hit		*hit;

	hit = hit_new(ray, &scene->objects);
	if (hit == NULL)
		return (color_cast(color_create(0.0, 0.0, 0.0)));
	color = hit_get_color(hit, &scene->objects, &scene->lights);
	hit_free(hit);
	return (color_cast(color));
}
