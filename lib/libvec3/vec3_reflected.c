/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_reflected.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:46:28 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/05 15:49:17 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec3.h"

t_vec3	vec3_reflected(t_vec3 vec, t_vec3 normal)
{
	return (vec3_sub(vec, vec3_mul(normal, 2.0 * vec3_dot(normal, vec))));
}
