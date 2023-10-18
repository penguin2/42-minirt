/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_from_to.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:23:36 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/18 20:25:36 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_ray	ray_from_to(t_vec3 from, t_vec3 to)
{
	return (ray_create(from, vec3_sub(to, from)));
}
