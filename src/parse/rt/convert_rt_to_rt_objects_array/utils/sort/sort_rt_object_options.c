/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rt_object_options.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:09:50 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/30 14:28:29 by rikeda           ###   ########.fr       */
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

void	sort_rt_object_options(const t_vla *rt_object)
{
	ft_sort(
		rt_object->array,
		rt_object->size,
		_cmp_option_string
		);
}
