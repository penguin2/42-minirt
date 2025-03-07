/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:12:03 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/05 16:30:51 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIANGLE_H
# define TRIANGLE_H

# include "libvec3.h"
# include "object.h"

typedef struct s_triangle{
	t_vec3	origin;
	t_vec3	edge[2];
	t_vec3	normal;
	double	area;
}	t_triangle;

t_triangle	*triangle_new(t_vec3 vertex[3]);
t_object	*triangle_object_new(t_vec3 vertex[3]);
void		triangle_free(void *triangle);
t_color		triangle_get_color(const t_object *object, const t_hit *hit);
bool		triangle_get_dist(const t_object *object, t_ray ray, double *dist);
t_vec3		triangle_get_normal(
				const t_object *object,
				t_ray ray,
				t_vec3 pos,
				t_vec3 *local_normal);

t_object_id	triangle_get_id(void);

#endif
