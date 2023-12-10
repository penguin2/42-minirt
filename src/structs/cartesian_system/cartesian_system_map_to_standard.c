/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cartesian_system_map_to_standard.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:59:01 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/29 19:51:32 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cartesian_system.h"

t_vec3	cartesian_system_map_to_standard(
			const t_cartesian_system *system,
			t_vec3 vec)
{
	return (vec3_create(
			system->axis_x.x * vec.x
			+ system->axis_y.x * vec.y
			+ system->axis_z.x * vec.z,
			system->axis_x.y * vec.x
			+ system->axis_y.y * vec.y
			+ system->axis_z.y * vec.z,
			system->axis_x.z * vec.x
			+ system->axis_y.z * vec.y
			+ system->axis_z.z * vec.z));
}
