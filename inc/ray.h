/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:56:20 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/11 16:09:44 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "libvec3.h"

typedef struct s_ray{
	t_vec3	origin;
	t_vec3	dir;
}	t_ray;

t_ray	ray_create(t_vec3 origin, t_vec3 dir);
t_vec3	ray_at(t_ray ray, double t);

#endif
