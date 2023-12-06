/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:04:57 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/06 18:59:07 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "generator.h"
#include "identifer_and_parameter.h"
#include <stddef.h>

/**
* @brief Convert from object identifer determined as rt file specification
*		 to option identifer determined as json file specification.
*
* @param simplified_option_key identifer defined in the rt file specification.
*
* @return identifer defined in the json file specification.
*/
static const char	*_get_formal_option_key(const char *simplified_option_key)
{
	if (ft_is_equal_str(simplified_option_key, K_AMBIENT_OMITTED))
		return (K_AMBIENT);
	else if (ft_is_equal_str(simplified_option_key, K_DIFFUSE_OMITTED))
		return (K_DIFFUSE);
	else if (ft_is_equal_str(simplified_option_key, K_SPECULAR_OMITTED))
		return (K_SPECULAR);
	else if (ft_is_equal_str(simplified_option_key, K_SHININESS_OMITTED))
		return (K_SHININESS);
	else if (ft_is_equal_str(simplified_option_key, K_REFLECT_OMITTED))
		return (K_REFLECT);
	else if (ft_is_equal_str(simplified_option_key, CHECKERBOARD_OMITTED))
		return (IS_CHECKERBOARD);
	else if (ft_is_equal_str(simplified_option_key, TEXTURE_MAP_OMITTED))
		return (TEXTURE_MAP);
	else if (ft_is_equal_str(simplified_option_key, BUMP_MAP_OMITTED))
		return (BUMP_MAP);
	else
		return (simplified_option_key);
}

/**
* @brief Convert rt file option identifer to json file option identifer
*		 and output option records to file.
*
* @param rt_object vla of required parameters and optional parameters.
* @param fd Output destination file descriptor.
*/
void	put_options(t_vla *rt_object, int fd)
{
	size_t		idx;
	const char	**option;
	const char	*formal_option_key;

	if (rt_object->size == 1)
		return ;
	idx = 1;
	while (idx < rt_object->size)
	{
		ft_putendl_fd(GENERATOR_COMMA, fd);
		option = rt_object->array[idx++];
		formal_option_key = _get_formal_option_key(option[OPTION_KEY_IDX]);
		put_key_and_value(formal_option_key, option[OPTION_VAL_IDX], false, fd);
		if (ft_is_equal_str(formal_option_key, K_REFLECT))
		{
			ft_putendl_fd(GENERATOR_COMMA, fd);
			put_key_and_value(IS_REFLECTIVE, TRUE_STRING, false, fd);
		}
	}
}
