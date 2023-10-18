/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_at.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:33:02 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/12 16:33:44 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec3.h"
#include "ray.h"

t_vec3	ray_at(t_ray ray, double t)
{
	return (vec3_add(ray.origin, vec3_mul(ray.dir, t)));
}
