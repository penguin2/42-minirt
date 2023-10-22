/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_projected.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 03:05:27 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/22 22:32:03 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec3.h"

/**
 * @brief project the given vector onto the given base plane (direction)
 *
 * @param vec projecting vector
 * @param normal non-zero normal vector for the plane on which vec is projected
 * @return projected vector of vec
 */
t_vec3	vec3_projected(t_vec3 vec, t_vec3 normal)
{
	return (vec3_sub(vec, vec3_mul(normal, vec3_dot(vec, normal))));
}
