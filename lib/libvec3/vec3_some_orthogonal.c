/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_some_orthogonal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:04:18 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/17 18:07:22 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec3.h"
#include "utils.h"

t_vec3	vec3_some_orthogonal(t_vec3 normal)
{
	t_vec3	vec;

	vec = vec3_projected(vec3_unit_x(), normal);
	if (is_zero(vec3_len(vec)))
		vec = vec3_projected(vec3_unit_y(), normal);
	return (vec3_unit(vec));
}
