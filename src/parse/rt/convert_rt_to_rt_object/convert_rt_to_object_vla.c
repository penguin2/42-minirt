/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_rt_to_object_vla.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:04:33 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/12 21:51:52 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include <stdlib.h>

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
