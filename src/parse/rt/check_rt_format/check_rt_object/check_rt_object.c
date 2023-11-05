/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rt_object.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 19:48:20 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/05 20:00:18 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "define.h"

int	check_rt_object(t_vla *rt_object)
{
	const char	**strings = rt_object->array[0];
	const char	*identifer = *strings;

	if (ft_is_equal_str(identifer, "A"))
		return (check_ambient_parameter(rt_object));
	else if (ft_is_equal_str(identifer, "C"))
		return (check_camera_parameter(rt_object));
	else if (ft_is_equal_str(identifer, "L"))
		return (check_spot_parameter(rt_object));
	else if (ft_is_equal_str(identifer, "cy"))
		return (check_cylinder_parameter(rt_object));
	else if (ft_is_equal_str(identifer, "pl"))
		return (check_plane_parameter(rt_object));
	else if (ft_is_equal_str(identifer, "sp"))
		return (check_sphere_parameter(rt_object));
	else
		return (ERROR);
}
