/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_mul.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:10:28 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/10 19:11:55 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec3.h"

t_vec3	vec3_mul(t_vec3 vec, double scalar)
{
	return (vec3_create(vec.x * scalar, vec.y * scalar, vec.z * scalar));
}
