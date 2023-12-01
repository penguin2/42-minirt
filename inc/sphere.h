/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:57:02 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/01 17:09:52 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H 

# include "cartesian_system.h"
# include "libvec3.h"
# include "object.h"

typedef struct s_sphere{
	t_vec3				center;
	double				radius;
	t_cartesian_system	system;
}	t_sphere;

# define SPHERE_LATITUDE_CYCLE (12)
# define SPHERE_LONGITUDE_CYCLE (6)

t_sphere	*sphere_new(t_vec3 center, double radius);
t_object	*sphere_object_new(t_vec3 center, double radius);
void		sphere_free(void *sphere);
t_color		sphere_get_color(const t_object *object, const t_hit *hit);
bool		sphere_get_dist(const t_object *object, t_ray ray, double *dist);
t_vec3		sphere_get_normal(const t_object *object, t_ray ray, t_vec3 pos);
t_object_id	sphere_get_id(void);

t_color		sphere_get_checkerboard_color(const t_sphere *sphere, t_vec3 pos);
t_color		sphere_get_texture_color(
				const t_sphere *sphere,
				const t_ppm_reader *texture_map,
				t_vec3 pos);
t_vec3		sphere_get_bump_normal(
				const t_sphere *sphere,
				const t_ppm_reader *bump_map,
				t_vec3 pos,
				t_vec3 normal);

#endif
