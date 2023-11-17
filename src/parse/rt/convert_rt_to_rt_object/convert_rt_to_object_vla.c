/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_rt_to_object_vla.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:04:33 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/17 14:34:49 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include <stdlib.h>

/**
* @brief Split line into rt_objects with vla as an content with string
*		 as an content, dividing the process by whether the string split
*		 by split is NULL or not, whether the second argument vla is NULL
*		 or not, and whether the string is an optional parameter or not.
*
* @param rt_object VLA of rt_object pointer.
* @param vla if a VLA was created before this function runs,
*			 its VLA, otherwise NULL.
* @param line string of deleted comments read from rt file.
*
* @return NULL if no strings remains after ft_split line with whitespace,
*			   otherwise, VLA
*/
static t_vla	*_append_strings_to_object_vla(t_vla *rt_object,
												t_vla *vla,
												char *line)
{
	char	**strings;

	strings = ft_split(line, RT_SPACE_STR);
	if (*strings == NULL)
	{
		ft_free_strings(strings);
		if (vla != NULL)
			ft_vla_append(rt_object, vla);
		vla = NULL;
	}
	else if (vla == NULL)
	{
		vla = ft_vla_new();
		ft_vla_append(vla, strings);
	}
	else if (ft_is_equal_str(strings[0], OPTION_START))
		ft_vla_append(vla, strings);
	else
	{
		ft_vla_append(rt_object, vla);
		vla = ft_vla_new();
		ft_vla_append(vla, strings);
	}
	return (vla);
}

/**
* @brief Read the rt file line by line,
*		 remove comments from the read string and append the split string
*		 with blanks to the VLA.
*
* @param rt_object VLA of rt_object pointer.
* @param fd file descriptor of rt file.
*/
void	convert_rt_to_object_vla(t_vla *rt_object, int fd)
{
	char	*line;
	t_vla	*vla;

	vla = NULL;
	while (true)
	{
		line = get_next_removed_comment_line(fd);
		if (line == NULL)
			break ;
		vla = _append_strings_to_object_vla(rt_object, vla, line);
		free(line);
	}
	if (vla != NULL)
		ft_vla_append(rt_object, vla);
}
