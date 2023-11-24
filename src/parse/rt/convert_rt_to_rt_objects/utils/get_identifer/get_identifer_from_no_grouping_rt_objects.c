/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_identifer_from_no_grouping_rt_objects.c        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:19:41 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/24 16:34:06 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

const char	*get_identifer_from_no_grouping_rt_objects(
										const t_vla *no_grouping_rt_objects,
										size_t idx)
{
	const t_vla	*rt_object = no_grouping_rt_objects->array[idx];
	const char	**strings = rt_object->array[0];

	return (strings[IDENTIFER_IDX]);
}
