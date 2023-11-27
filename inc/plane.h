/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:59:52 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/27 10:04:29 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H

# include "libvec3.h"
# include "object.h"

# define UNIT_TEXTURE_SIZE (100)

typedef struct s_plane{
	t_vec3	origin;
	t_vec3	normal;
	t_vec3	axis_u;
	t_vec3	axis_v;
}	t_plane;

t_plane		*plane_new(t_vec3 origin, t_vec3 normal);
t_object	*plane_object_new(t_vec3 origin, t_vec3 normal);
void		plane_free(void *plane);
t_color		plane_get_color(const t_object *object, const t_hit *hit);
bool		plane_get_dist(const t_object *object, t_ray ray, double *dist);
t_vec3		plane_get_normal(const t_object *object, t_ray ray, t_vec3 pos);
t_object_id	plane_get_id(void);

t_color		plane_get_checkerboard_color(const t_plane *plane, t_vec3 pos);
t_color		plane_get_texture_color(
				const t_plane *plane,
				const t_ppm_reader *texture_map,
				t_vec3 pos);

#endif
