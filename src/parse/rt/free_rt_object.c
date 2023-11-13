/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_rt_object.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 21:31:18 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/13 19:51:05 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "libft.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

/**
* @brief Nest two or three levels of VLA, and free rt_objects,
*		 which is a strcture of strings connected under the VLA.
*		 if the identifier and parameters of the rt file are normal values,
*		 the grouping_same_objects function will work and
*		 rt_objects will one level deeper.
*
* @param rt_object vla of rt objects
* @param one_step_deep if true, perform another deep free,
*		 if true, perform free one step deeper.
*/
void	free_rt_object(t_vla *rt_object, bool one_step_deep)
{
	size_t	idx;

	idx = 0;
	while (idx < rt_object->size)
	{
		if (one_step_deep)
			free_rt_object(rt_object->array[idx], false);
		else
			ft_vla_free(rt_object->array[idx], ft_free_strings);
		free(rt_object->array[idx]);
		idx++;
	}
	free(rt_object->array);
}
