/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rt_object_option_format.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:52:37 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/13 19:58:19 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "parse.h"
#include "utils.h"
#include "message_parse.h"
#include "identifer_and_parameter.h"
#include <stddef.h>

static int	_is_optionless_rt_object(const char *identifer)
{
	if (ft_is_equal_str(identifer, ID_AMBIENT)
		|| ft_is_equal_str(identifer, ID_SPOT)
		|| ft_is_equal_str(identifer, ID_CAMERA))
		return (ERROR);
	return (SUCCESS);
}

static int	_check_optionless(const t_vla *rt_object)
{
	if (rt_object->size == 1)
		return (SUCCESS);
	else
	{
		print_error(RT_OPTIONLESS);
		return (ERROR);
	}
}

/**
* @brief Sort the option parameters in ascii order, looking for
*		 the first non-option object identifer, and check that the option
*		 is a proprietary option and that there are no duplicate options.
*
* @param rt_objects vla with string as content vla with string as content.
*
* @return SUCCESS if rt_objects follows the format of the rt file,
*				  otherwise ERROR.
*/
int	check_rt_object_option_format(const t_vla *rt_object)
{
	size_t		idx;
	char		**strings;
	const char	*identifer = *((char **)rt_object->array[0]);
	const char	*prev_option_key;

	if (_is_optionless_rt_object(identifer))
		return (_check_optionless(rt_object));
	sort_rt_object_options(rt_object);
	prev_option_key = NULL;
	idx = 1;
	while (idx < rt_object->size)
	{
		strings = rt_object->array[idx++];
		if (!is_option_key(strings[OPTION_KEY_IDX], identifer))
			return (ERROR);
		else if (is_duplicate(prev_option_key, strings[OPTION_KEY_IDX]))
		{
			print_error(RT_OPTION_DUPLICATE);
			return (ERROR);
		}
		prev_option_key = strings[OPTION_KEY_IDX];
	}
	return (SUCCESS);
}
