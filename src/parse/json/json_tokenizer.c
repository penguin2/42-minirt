/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_tokenizer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 22:11:22 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/17 16:43:00 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	str = ft_skip_charsets(str, " \t\n");
	while (*str != '\0')
	{
		if (ft_strchr("{}[]:,", *str))
			ft_vla_append(token, ft_strdup_n(str++, 1));
		else if (*str == '"')
		{
			_vla_append_str(token, str, "\"");
			str = ft_skip_non_charsets((str + 1), "\"");
			str++;
		}
		else
		{
			_vla_append_str(token, str, "{}[]:, \t\n\"");
			str = ft_skip_non_charsets(str, "{}[]:, \t\n\"");
		}
		str = ft_skip_charsets(str, " \t\n");
	}
}

t_vla	*json_tokenizer(const char *str)
{
	t_vla	*token;

	if (str == NULL)
		return (NULL);
	token = (t_vla *)ft_xcalloc(1, sizeof(t_vla));
	ft_vla_init(token);
	_json_token_create(token, str);
	return (token);
}
