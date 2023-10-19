/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 22:11:22 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/25 14:35:20 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"

static void	_vla_append_str(t_vla *token, const char *str, const char *charsets)
{
	const char	*key_end;

	if (ft_is_equal_str(charsets, "\""))
	{
		key_end = ft_skip_non_charsets((str + 1), charsets);
		ft_vla_append(token, ft_strdup_n(str, key_end - str + 1));
	}
	else
	{
		key_end = ft_skip_non_charsets(str, charsets);
		ft_vla_append(token, ft_strdup_n(str, key_end - str));
	}
}

static void	_json_token_create(t_vla *token, const char *str)
{
	while (*str != '\0')
	{
		if (ft_strchr(JSON_TOKEN_CHARSETS, *str))
			ft_vla_append(token, ft_strdup_n(str++, 1));
		else if (*str == '"')
		{
			_vla_append_str(token, str, "\"");
			str = ft_skip_non_charsets((str + 1), "\"");
			str++;
		}
		else
		{
			_vla_append_str(token, str, JSON_SPACE_AND_TOKEN_CHARSETS);
			str = ft_skip_non_charsets(str, JSON_SPACE_AND_TOKEN_CHARSETS);
		}
		str = ft_skip_charsets(str, JSON_SPACE_CHARSETS);
	}
}

t_vla	*tokenize(const char *str)
{
	t_vla	*token;

	if (str == NULL)
		return (NULL);
	str = ft_skip_charsets(str, JSON_SPACE_CHARSETS);
	if (*str == '\0')
		return (NULL);
	token = (t_vla *)ft_vla_new();
	_json_token_create(token, str);
	return (token);
}
