/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator_rt_object.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:21:12 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/11 17:45:37 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"
#include "libft.h"
#include <stdbool.h>

void	generator_rt_object(t_vla *rt_object, int fd)
{
	const char	**strings = rt_object->array[0];
	const char	*identifer = strings[0];
	bool		is_with_comma;

	if (ft_is_equal_str(identifer, "A"))
		is_with_comma = generator_ambient_object(rt_object, fd);
	else if (ft_is_equal_str(identifer, "C"))
		is_with_comma = generator_camera_object(rt_object, fd);
	else if (ft_is_equal_str(identifer, "L"))
		is_with_comma = generator_spot_object(rt_object, fd);
	else if (ft_is_equal_str(identifer, "cy"))
		is_with_comma = generator_cylinder_object(rt_object, fd);
	else if (ft_is_equal_str(identifer, "pl"))
		is_with_comma = generator_plane_object(rt_object, fd);
	else if (ft_is_equal_str(identifer, "sp"))
		is_with_comma = generator_sphere_object(rt_object, fd);
	else
		return ;
	put_options(rt_object, is_with_comma, fd);
}
