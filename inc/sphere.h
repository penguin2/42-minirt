/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:57:02 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/19 23:54:34 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H 

# include "object.h"
# include "libvec3.h"

typedef struct s_sphere{
	t_vec3	center;
	double	radius;
}	t_sphere;

t_sphere	*sphere_new(t_vec3 center, double radius);
void		sphere_free(void *sphere);
bool		sphere_get_dist(const t_object *object, t_ray ray, double *dist);
t_vec3		sphere_get_normal(const t_object *object, t_ray ray, t_vec3 pos);

#endif
