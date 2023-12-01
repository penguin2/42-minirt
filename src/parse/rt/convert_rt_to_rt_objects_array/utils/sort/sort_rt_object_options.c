/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rt_object_options.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:09:50 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/01 16:51:53 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include <stdbool.h>
#include <stddef.h>

static bool	_cmp_option_string(const void *ptr1, const void *ptr2)
{
	const char	**strings1 = (const char **)ptr1;
	const char	**strings2 = (const char **)ptr2;
	const char	*option_string1 = strings1[OPTION_KEY_IDX];
	const char	*option_string2 = strings2[OPTION_KEY_IDX];

	return (ft_strcmp(option_string1, option_string2) < 0);
}

/**
* @brief Sort rt_object option parameter.
*		 [Warning]: rt_object[0] is not an optional parameter,
*		 but a required parameter,
*		 and this function sorts by excluding the required parameters,
*		 since this function sorts only optional parameters.
*
* @param rt_object vla of parameters include option parameters
*/
void	sort_rt_object_options(const t_vla *rt_object)
{
	ft_sort(
		&rt_object->array[1],
		rt_object->size - 1,
		_cmp_option_string
		);
}
