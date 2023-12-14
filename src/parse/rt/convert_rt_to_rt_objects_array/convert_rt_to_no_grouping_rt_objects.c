/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_rt_to_no_grouping_rt_objects.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:04:33 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/14 17:13:44 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libgnl.h"
#include "parse.h"
#include "generator.h"
#include <stdlib.h>

/**
* @brief Split line into rt_objects with vla as an content with string
*		 as an content, dividing the process by whether the string split
*		 by split is NULL or not, whether the second argument vla is NULL
*		 or not, and whether the string is an optional parameter or not.
*
* @param no_grouping_rt_objects VLA of rt_object pointer.
* @param rt_object if a VLA was created before this function runs,
*			 its VLA, otherwise NULL.
* @param line string of deleted comments read from rt file.
*
* @return Return rt_object in the process of creation.
*/
static t_vla	*_append_strings_to_rt_object(t_vla *no_grouping_rt_objects,
												t_vla *rt_object,
												char *line)
{
	char	**strings;

	strings = ft_split(line, RT_SPACE_STR);
	if (*strings == NULL)
		ft_free_strings(strings);
	else if (rt_object == NULL)
	{
		rt_object = ft_vla_new();
		ft_vla_append(rt_object, strings);
	}
	else if (ft_is_equal_str(strings[OPTION_START_IDX], OPTION_START))
		ft_vla_append(rt_object, strings);
	else
	{
		ft_vla_append(no_grouping_rt_objects, rt_object);
		rt_object = ft_vla_new();
		ft_vla_append(rt_object, strings);
	}
	return (rt_object);
}

/**
* @brief Read the rt file line by line,
*		 remove comments from the read string
*		 and append the splitted strings to the VLA(rt_object)
*		 and append that VLA(rt_object) to no_grouping_rt_objects.
*
* @param no_grouping_rt_object VLA of rt_object pointer.
* @param fd file descriptor of rt file.
*/
void	convert_rt_to_no_grouping_rt_objects(t_vla *no_grouping_rt_objects,
												int fd)
{
	char	*line;
	t_vla	*rt_object;

	rt_object = NULL;
	while (true)
	{
		line = get_next_removed_comment_line(fd);
		if (line == NULL)
			break ;
		rt_object = _append_strings_to_rt_object(
				no_grouping_rt_objects, rt_object, line);
		free(line);
	}
	if (rt_object != NULL)
		ft_vla_append(no_grouping_rt_objects, rt_object);
	get_next_line(fd, NULL, GNL_MODE_RESET);
}
