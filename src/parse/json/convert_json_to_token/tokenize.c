/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 22:11:22 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/28 14:50:11 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include <stddef.h>

/**
* @brief Skip strings enclosed in double quotes
*		 If the double quotes is not closed, skip to the null-terminator
*
* @param str String beginning with a double quote
*
* @return Pointer to next character of closing double quote or null character
*/
static const char	*_skip_key_string(const char *str)
{
	str++;
	str = ft_skip_non_charsets(str, JSON_KEY_CHARSETS);
	if (*str == KEY)
		str++;
	return (str);
}

/**
* @brief {}[]:, -> Allocate space for only one character
*        KEY -> Allocate area from double quote to double quote
*        VALUE -> Allocate space to other token or whitespace
*
* @param token Variable length array for storing json tokens
* @param str All characters read from the json file
*
* @return Pointer to next json token string
*/
static const char	*_vla_append_str(t_vla *token, const char *str)
{
	const char	*key_end;

	if (ft_strchr(JSON_TOKEN_CHARSETS, *str))
		key_end = str + 1;
	else if (*str == KEY)
		key_end = _skip_key_string(str);
	else
		key_end = ft_skip_non_charsets(str, JSON_SPACE_AND_TOKEN_CHARSETS);
	ft_vla_append(token, ft_strndup(str, key_end - str));
	return (ft_skip_charsets(key_end, JSON_SPACE_CHARSETS));
}

t_vla	*tokenize(const char *str)
{
	t_vla	*token;

	str = ft_skip_charsets(str, JSON_SPACE_CHARSETS);
	if (*str == '\0')
		return (NULL);
	token = (t_vla *)ft_vla_new();
	while (*str != '\0')
		str = _vla_append_str(token, str);
	return (token);
}
