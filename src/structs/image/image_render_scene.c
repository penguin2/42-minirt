/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_render_scene.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:12:18 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/03 12:48:57 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"
#include "image.h"
#include "libcolor.h"
#include "libvec3.h"
#include "ray.h"
#include <mlx.h>
#include <stddef.h>

static int	_get_ray_color(t_scene *scene, t_ray ray);

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
			_get_ray_color(scene, ray_from_to(scene->camera.eye, pixel)));
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

/**
 * @brief tracing the given ray,
 * 		if the ray hits a certain object, it calculates the color of that hit.
 *
 * @param scene information of the scene
 * @param ray given ray to trace
 * @return color of the hit if the ray hits a certain object,
 * 		otherwise the default color (black!?)
 */
static int	_get_ray_color(t_scene *scene, t_ray ray)
{
	t_color		color;
	t_hit		*hit;

	hit = hit_new(ray, &scene->objects);
	if (hit == NULL)
		return (color_cast(color_black()));
	color = hit_get_color(hit, &scene->objects, &scene->lights);
	hit_free(hit);
	return (color_cast(color));
}
