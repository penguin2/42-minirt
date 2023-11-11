/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_generator_from_rt_object.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:09:06 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/11 20:20:12 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include "generator.h"
#include <stddef.h>

static void	_generator_rt_object_array(t_vla *rt_object_array, int fd)
{
	const char	*identifer = get_identifer_from_rt_objects(rt_object_array, 0);
	size_t		idx;
	t_vla		*rt_object;

	idx = 0;
	put_indent(1, fd);
	put_key_and_colon(identifer, fd);
	ft_putstr_fd(GENERATOR_LIST_START, fd);
	while (idx < rt_object_array->size)
	{
		rt_object = rt_object_array->array[idx++];
		ft_putendl_fd(GENERATOR_DICT_START, fd);
		generator_rt_object(rt_object, fd);
		ft_putchar_fd('\n', fd);
		put_indent(1, fd);
		ft_putstr_fd(GENERATOR_DICT_END, fd);
		if (idx != rt_object_array->size)
			ft_putstr_fd(GENERATOR_VALUE_SEPARATOR, fd);
	}
	ft_putstr_fd(GENERATOR_LIST_END, fd);
}

void	json_generator_from_rt_object(t_vla *rt_objects, int fd)
{
	size_t	idx;
	t_vla	*rt_object_array;

	idx = 0;
	ft_putendl_fd(GENERATOR_DICT_START, fd);
	while (idx < rt_objects->size)
	{
		rt_object_array = rt_objects->array[idx++];
		_generator_rt_object_array(rt_object_array, fd);
		if (idx != rt_objects->size)
			ft_putendl_fd(GENERATOR_COMMA, fd);
		else
		{
			put_indent(1, fd);
			ft_putchar_fd('\n', fd);
		}
	}
	ft_putendl_fd(GENERATOR_DICT_END, fd);
}
