/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_identifer_from_rt_objects_array.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:19:41 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/24 19:34:35 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"

const char	*get_identifer_from_rt_objects_array(const t_vla *rt_objects_array,
												size_t idx)
{
	const t_vla	*rt_objects = rt_objects_array->array[idx];
	const t_vla	*rt_object = rt_objects->array[0];
	const char	**strings = rt_object->array[0];

	return (strings[IDENTIFER_IDX]);
}
