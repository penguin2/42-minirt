/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:00:54 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/19 23:54:54 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include "object.h"
# include "libvec3.h"

typedef struct s_cylinder{
	t_vec3	center;
	t_vec3	dir;
	double	radius;
	double	half_height;
}	t_cylinder;

t_cylinder	*cylinder_new(
				t_vec3 center,
				t_vec3 dir,
				double radius,
				double half_height);
void		cylinder_free(void *cylinder);
bool		cylinder_get_dist(const t_object *object, t_ray ray, double *dist);
t_vec3		cylinder_get_normal(const t_object *object, t_ray ray, t_vec3 pos);

#endif
