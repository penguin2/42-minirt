/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_rt_to_rt_object.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:51:45 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/16 17:28:48 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include "define.h"
#include <stdbool.h>

int	convert_rt_to_rt_object(t_vla *rt_object, int fd)
{
	convert_rt_to_object_vla(rt_object, fd);
	if (check_rt_object_format(rt_object) == ERROR)
	{
		free_rt_object(rt_object, false);
		return (ERROR);
	}
	sort_rt_objects(rt_object);
	grouping_same_objects(rt_object);
	if (check_duplicate_spot_light(rt_object) == ERROR)
	{
		free_rt_object(rt_object, true);
		return (ERROR);
	}
	return (SUCCESS);
}
