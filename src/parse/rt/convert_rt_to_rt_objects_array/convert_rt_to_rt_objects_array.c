/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_rt_to_rt_objects_array.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:51:45 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/24 19:24:56 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include "define.h"
#include <stdbool.h>

/**
* @brief Create rt_objects.
*		 if the creation fails, rt_objects_array created
*		 in the process are free and ERROR is returned.
*		 Until the grouping_same_rt_objects function is executed,
*		 rt_objects is no_grouping_rt_objects.
*
* @param rt_objects_array VLA to store rt_objects to be created.
* @param fd File descriptors for files with the rt extension.
*
* @return ERROR if failed, SUCCESS if successful.
*/
int	convert_rt_to_rt_objects_array(t_vla *rt_objects_array, int fd)
{
	convert_rt_to_no_grouping_rt_objects(rt_objects_array, fd);
	if (check_rt_object_format(rt_objects_array) == ERROR)
	{
		free_no_grouping_rt_objects(rt_objects_array);
		return (ERROR);
	}
	sort_no_grouping_rt_objects(rt_objects_array);
	grouping_same_rt_objects(rt_objects_array);
	if (MODE == MODE_MANDATORY
		&& check_duplicate_spot(rt_objects_array) == ERROR)
	{
		free_rt_objects_array(rt_objects_array);
		return (ERROR);
	}
	return (SUCCESS);
}
