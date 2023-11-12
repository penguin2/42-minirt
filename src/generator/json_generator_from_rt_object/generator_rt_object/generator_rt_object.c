/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator_rt_object.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:21:12 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/12 22:32:41 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"
#include "libft.h"
#include <stdbool.h>

void	generator_rt_object(t_vla *rt_object, int fd)
{
	const char	**strings = rt_object->array[0];
	const char	*identifer = strings[0];

	if (ft_is_equal_str(identifer, "A"))
		generator_ambient_object(rt_object, fd);
	else if (ft_is_equal_str(identifer, "C"))
		generator_camera_object(rt_object, fd);
	else if (ft_is_equal_str(identifer, "L"))
		generator_spot_object(rt_object, fd);
	else if (ft_is_equal_str(identifer, "cy"))
		generator_cylinder_object(rt_object, fd);
	else if (ft_is_equal_str(identifer, "pl"))
		generator_plane_object(rt_object, fd);
	else if (ft_is_equal_str(identifer, "sp"))
		generator_sphere_object(rt_object, fd);
}
