/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:00:54 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/05 16:28:55 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include "cartesian_system.h"
# include "libvec3.h"
# include "object.h"

# define CYLINDER_CYCLE (12)

typedef struct s_cylinder{
	t_vec3				center;
	t_cartesian_system	system;
	double				radius;
	double				half_height;
}	t_cylinder;

t_cylinder	*cylinder_new(
				t_vec3 center,
				t_vec3 dir,
				double radius,
				double half_height);
t_object	*cylinder_object_new(
				t_vec3 center,
				t_vec3 dir,
				double radius,
				double half_height);
void		cylinder_free(void *cylinder);
t_color		cylinder_get_color(const t_object *object, const t_hit *hit);
bool		cylinder_get_dist(const t_object *object, t_ray ray, double *dist);
t_vec3		cylinder_get_normal(
				const t_object *object,
				t_ray ray,
				t_vec3 pos,
				t_vec3 *local_normal);

t_object_id	cylinder_get_id(void);

t_color		cylinder_get_checkerboard_color(
				const t_cylinder *cylinder,
				t_vec3 pos);
t_color		cylinder_get_texture_color(
				const t_cylinder *cylinder,
				const t_ppm_reader *texture_map,
				t_vec3 pos);
t_vec3		cylinder_get_bump_normal(
				const t_cylinder *cylinder,
				const t_ppm_reader *bump_map,
				t_vec3 pos,
				t_vec3 normal);

#endif
