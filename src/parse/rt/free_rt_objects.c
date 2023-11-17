/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_rt_object.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 21:31:18 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/17 18:34:41 by rikeda           ###   ########.fr       */
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
* @param rt_objects vla of rt object
* @param one_step_deep if true, perform another deep free,
*		 if true, perform free one step deeper.
*/
void	free_rt_objects(t_vla *rt_objects, bool one_step_deep)
{
	size_t	idx;

	idx = 0;
	while (idx < rt_objects->size)
	{
		if (one_step_deep)
			free_rt_objects(rt_objects->array[idx], false);
		else
			ft_vla_free(rt_objects->array[idx], ft_free_strings);
		free(rt_objects->array[idx]);
		idx++;
	}
	free(rt_objects->array);
}
