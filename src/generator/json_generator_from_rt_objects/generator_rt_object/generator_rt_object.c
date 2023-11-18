/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator_rt_object.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:21:12 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/18 16:00:55 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"
#include "identifer_and_parameter.h"
#include "libft.h"
#include <stdbool.h>

/**
* @brief Call the generator function corresponding to the object.
*		 The called function takes each object and fd as arguments,
*		 determines the KEY to output from the sequence define in the rt file,
*		 and outputs the record.
*		 The first parameter does not output a comma,
*		 the second and subsequent parameters output comma,
*		 and then the record is output.
*
* @param rt_object vla of required parameters and optional parameters.
* @param fd Output destination file descriptor.
*/
void	generator_rt_object(t_vla *rt_object, int fd)
{
	const char	**strings = rt_object->array[0];
	const char	*identifer = strings[IDENTIFER_IDX];

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
