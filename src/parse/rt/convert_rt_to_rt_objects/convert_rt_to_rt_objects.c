/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_rt_to_rt_objects.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:51:45 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/24 17:49:26 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include "define.h"
#include <stdbool.h>

/**
* @brief Create rt_objects.
*		 if the creation fails, rt_objects created in the process are free
*		 and ERROR is returned.
*		 Until the grouping_same_rt_objects function is executed,
*		 rt_objects is no_grouping_rt_objects.
*
* @param rt_objects VLA to store rt_objects to be created.
* @param fd File descriptors for files with the rt extension.
*
* @return ERROR if failed, SUCCESS if successful.
*/
int	convert_rt_to_rt_objects(t_vla *rt_objects, int fd)
{
	convert_rt_to_no_grouping_rt_objects(rt_objects, fd);
	if (check_rt_object_format(rt_objects) == ERROR)
	{
		free_no_grouping_rt_objects(rt_objects);
		return (ERROR);
	}
	sort_no_grouping_rt_objects(rt_objects);
	grouping_same_rt_objects(rt_objects);
	if (MODE == MODE_MANDATORY && check_duplicate_spot(rt_objects) == ERROR)
	{
		free_rt_objects(rt_objects);
		return (ERROR);
	}
	return (SUCCESS);
}
