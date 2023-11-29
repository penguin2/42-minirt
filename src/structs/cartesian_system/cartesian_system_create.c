/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cartesian_system_create.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:02:03 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/29 17:02:46 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cartesian_system.h"

t_cartesian_system	cartesian_system_create(
						t_vec3 axis_x,
						t_vec3 axis_y,
						t_vec3 axis_z)
{
	t_cartesian_system	new;

	new.axis_x = axis_x;
	new.axis_y = axis_y;
	new.axis_z = axis_z;
	return (new);
}
