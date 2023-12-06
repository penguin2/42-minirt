/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_option_key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:16:07 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/06 18:59:23 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "identifer_and_parameter.h"
#include "message_parse.h"
#include "define.h"
#include "utils.h"
#include <stdbool.h>

static bool	_is_mandatory_object_identifer(const char *identifer)
{
	if (ft_is_equal_str(identifer, ID_PLANE)
		|| ft_is_equal_str(identifer, ID_SPHERE)
		|| ft_is_equal_str(identifer, ID_CYLINDER))
		return (true);
	else
		return (false);
}

static bool	_is_bonus_option_key(const char *option_key, const char *identifer)
{
	if (ft_is_equal_str(option_key, K_REFLECT_OMITTED)
		|| ft_is_equal_str(option_key, TEXTURE_MAP_OMITTED)
		|| ft_is_equal_str(option_key, BUMP_MAP_OMITTED)
		|| ft_is_equal_str(option_key, CHECKERBOARD_OMITTED))
	{
		if (MODE == MODE_MANDATORY)
			print_error(RT_OMITTED_KEY);
		else if (ft_is_equal_str(option_key, CHECKERBOARD_OMITTED)
			&& !_is_mandatory_object_identifer(identifer))
			print_error(RT_CHECKERBOARD);
		else
			return (true);
	}
	else
		print_error(RT_OPTION_IDENTIFER_INVALID);
	return (false);
}

bool	is_option_key(const char *option_key, const char *identifer)
{
	if (ft_is_equal_str(option_key, K_AMBIENT_OMITTED)
		|| ft_is_equal_str(option_key, K_DIFFUSE_OMITTED)
		|| ft_is_equal_str(option_key, K_SPECULAR_OMITTED)
		|| ft_is_equal_str(option_key, K_SHININESS_OMITTED))
		return (true);
	else
		return (_is_bonus_option_key(option_key, identifer));
}
