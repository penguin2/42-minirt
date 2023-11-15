/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator_rt_object.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:21:12 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/16 15:38:42 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"
#include "identifer_and_parameter.h"
#include "libft.h"
#include <stdbool.h>

void	generator_rt_object(t_vla *rt_object, int fd)
{
	const char	**strings = rt_object->array[0];
	const char	*identifer = strings[0];

	if (ft_is_equal_str(identifer, ID_AMBIENT))
		generator_ambient_object(rt_object, fd);
	else if (ft_is_equal_str(identifer, ID_CAMERA))
		generator_camera_object(rt_object, fd);
	else if (ft_is_equal_str(identifer, ID_SPOT))
		generator_spot_object(rt_object, fd);
	else if (ft_is_equal_str(identifer, ID_CYLINDER))
		generator_cylinder_object(rt_object, fd);
	else if (ft_is_equal_str(identifer, ID_PLANE))
		generator_plane_object(rt_object, fd);
	else if (ft_is_equal_str(identifer, ID_SPHERE))
		generator_sphere_object(rt_object, fd);
	else if (ft_is_equal_str(identifer, ID_TRIANGLE))
		generator_triangle_object(rt_object, fd);
	else if (ft_is_equal_str(identifer, ID_QUADRIC))
		generator_quadric_object(rt_object, fd);
}
