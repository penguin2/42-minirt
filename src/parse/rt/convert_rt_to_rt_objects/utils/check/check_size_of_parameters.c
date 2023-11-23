/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_size_of_parameters.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:21:44 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/23 22:16:58 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "define.h"
#include "utils.h"
#include "message_parse.h"
#include <stddef.h>

/**
* @brief Check if the format of the rt file is followed.
*		 Ensure that required parameters are not identifer only,
*		 that they are less than the maximum value of required parameters,
*		 that they are less than the maximum value of optional parameters,
*		 and that optional parameters begin with an optional start string
*		 and consist only of an optional string and optional parameters,
*		 and that optional parameters are appropriate.
*
* @param rt_objects vla with string as content vla with string as content.
* @param required_parameters_max_size required parameters max size
* @param optional_parameters_max_size optional parameters max size
*
* @return SUCCESS if the rt file format is followed, otherwise ERROR.
*/
int	check_size_of_parameters(const t_vla *rt_object,
							t_required_max_size required_parameters_max_size,
							t_optional_max_size optional_parameters_max_size)
{
	const char	**required_parameters = rt_object->array[0];
	const char	**optional_parameters;
	size_t		idx;

	if (1 == ft_strings_len(required_parameters)
		|| required_parameters_max_size < ft_strings_len(required_parameters)
		|| optional_parameters_max_size < rt_object->size - 1)
	{
		print_error(RT_PARAMETER_SIZE);
		return (ERROR);
	}
	idx = 1;
	while (idx < rt_object->size)
	{
		optional_parameters = rt_object->array[idx++];
		if (ft_strings_len(optional_parameters) != 3
			|| !ft_is_equal_str(
				optional_parameters[OPTION_START_IDX], OPTION_START))
		{
			print_error(RT_OPTION_PARAMETER_FMT);
			return (ERROR);
		}
	}
	return (check_rt_object_option_format(rt_object));
}
