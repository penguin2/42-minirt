/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cartesian_system_get_coord.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:58:10 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/29 19:50:29 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cartesian_system.h"

t_vec3	cartesian_system_map_from_standard(
			const t_cartesian_system *system,
			t_vec3 standard_vec)
{
	return (vec3_create(
			vec3_dot(system->axis_x, standard_vec),
			vec3_dot(system->axis_y, standard_vec),
			vec3_dot(system->axis_z, standard_vec)));
}
