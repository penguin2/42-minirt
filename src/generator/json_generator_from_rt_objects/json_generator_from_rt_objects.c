/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_generator_from_rt_objects.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:09:06 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/18 15:45:25 by rikeda           ###   ########.fr       */
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
* @param rt_object_array vla of rt_object.
* @param fd Output destination file descriptor.
*/
static void	_generator_rt_object_array(t_vla *rt_object_array, int fd)
{
	const char	*identifer = get_identifer_from_rt_objects(rt_object_array, 0);
	size_t		idx;
	t_vla		*rt_object;

	put_indent(1, fd);
	put_key_and_colon(identifer, fd);
	ft_putstr_fd(GENERATOR_LIST_START, fd);
	idx = 0;
	while (idx < rt_object_array->size)
	{
		ft_putendl_fd(GENERATOR_DICT_START, fd);
		rt_object = rt_object_array->array[idx++];
		generator_rt_object(rt_object, fd);
		ft_putchar_fd('\n', fd);
		put_indent(1, fd);
		ft_putstr_fd(GENERATOR_DICT_END, fd);
		if (idx != rt_object_array->size)
			ft_putstr_fd(GENERATOR_VALUE_SEPARATOR, fd);
	}
	ft_putstr_fd(GENERATOR_LIST_END, fd);
}

/**
* @brief Output the outermost '{' of the json file,
*		 comma-separate the required and optional parameters for each object,
*		 and output the outermost '}'.
*
* @param rt_objects vla of rt_object array.
* @param fd Output destination file descriptor.
*/
void	json_generator_from_rt_objects(t_vla *rt_objects, int fd)
{
	size_t	idx;
	t_vla	*rt_object_array;

	ft_putendl_fd(GENERATOR_DICT_START, fd);
	idx = 0;
	while (idx < rt_objects->size)
	{
		rt_object_array = rt_objects->array[idx++];
		_generator_rt_object_array(rt_object_array, fd);
		if (idx != rt_objects->size)
			ft_putendl_fd(GENERATOR_COMMA, fd);
		else
			ft_putchar_fd('\n', fd);
	}
	ft_putendl_fd(GENERATOR_DICT_END, fd);
}
