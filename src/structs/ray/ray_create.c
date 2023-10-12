/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:32:12 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/12 16:32:49 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_ray	ray_create(t_vec3 origin, t_vec3 dir)
{
	t_ray	new;

	new.origin = origin;
	new.dir = dir;
	return (new);
}
