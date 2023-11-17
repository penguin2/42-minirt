/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_rt_to_rt_object.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:51:45 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/17 18:37:55 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include "define.h"
#include <stdbool.h>

int	convert_rt_to_rt_objects(t_vla *rt_objects, int fd)
{
	convert_rt_to_object_vla(rt_objects, fd);
	if (check_rt_object_format(rt_objects) == ERROR)
	{
		free_rt_objects(rt_objects, false);
		return (ERROR);
	}
	sort_rt_objects(rt_objects);
	grouping_same_objects(rt_objects);
	if (MODE == MODE_MANDATORY && check_duplicate_spot(rt_objects) == ERROR)
	{
		free_rt_objects(rt_objects, true);
		return (ERROR);
	}
	return (SUCCESS);
}
