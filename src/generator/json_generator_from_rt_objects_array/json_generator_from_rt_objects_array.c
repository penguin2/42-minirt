/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_generator_from_rt_objects_array.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:09:06 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/24 19:37:43 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include "generator.h"
#include <stddef.h>

/**
* @brief Output in the following order:
*		 indent -> rt_object identifer -> colon -> GENERATOR_LIST_START,
*		 and then output each rt_object surrounded by '{' '}',
*		 and output ']' after all rt_objects in the rt_object_array
*		 have been output.
*
* @param rt_objects vla of rt_object.
* @param fd Output destination file descriptor.
*/
static void	_generator_rt_object_array(t_vla *rt_objects,
										const char *identifer,
										int fd)
{
	size_t		idx;
	t_vla		*rt_object;

	put_indent(1, fd);
	put_key_and_colon(identifer, fd);
	ft_putstr_fd(GENERATOR_LIST_START, fd);
	idx = 0;
	while (idx < rt_objects->size)
	{
		ft_putendl_fd(GENERATOR_DICT_START, fd);
		rt_object = rt_objects->array[idx++];
		generator_rt_object(rt_object, fd);
		ft_putchar_fd('\n', fd);
		put_indent(1, fd);
		ft_putstr_fd(GENERATOR_DICT_END, fd);
		if (idx != rt_objects->size)
			ft_putstr_fd(GENERATOR_VALUE_SEPARATOR, fd);
	}
	ft_putstr_fd(GENERATOR_LIST_END, fd);
}

/**
* @brief Output the outermost '{' of the json file,
*		 comma-separate the required and optional parameters for each object,
*		 and output the outermost '}'.
*
* @param rt_objects_array vla of rt_objects array.
* @param fd Output destination file descriptor.
*/
void	json_generator_from_rt_objects_array(t_vla *rt_objects_array, int fd)
{
	size_t	idx;

	ft_putendl_fd(GENERATOR_DICT_START, fd);
	idx = 0;
	while (idx < rt_objects_array->size)
	{
		_generator_rt_object_array(
			rt_objects_array->array[idx],
			get_identifer_from_rt_objects_array(rt_objects_array, idx),
			fd);
		idx++;
		if (idx != rt_objects_array->size)
			ft_putendl_fd(GENERATOR_COMMA, fd);
		else
			ft_putchar_fd('\n', fd);
	}
	ft_putendl_fd(GENERATOR_DICT_END, fd);
}
