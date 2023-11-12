/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:32:12 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/12 16:41:09 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "utils.h"

t_ray	ray_create(t_vec3 origin, t_vec3 dir)
{
	t_ray	new;

	new.dir = vec3_unit(dir);
	new.origin = vec3_add(origin, vec3_mul(new.dir, EPS));
	return (new);
}
