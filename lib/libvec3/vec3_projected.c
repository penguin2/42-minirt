/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_projected.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 03:05:27 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/20 04:00:48 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec3.h"

t_vec3	vec3_projected(t_vec3 vec, t_vec3 normal)
{
	return (vec3_sub(vec, vec3_mul(normal, vec3_dot(vec, normal))));
}
