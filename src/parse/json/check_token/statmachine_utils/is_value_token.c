/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_value_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 00:35:26 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/24 15:18:05 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"

/**
* @brief determine if the token is a VALUE token
*
* @param str token str
*
* @return true if it is a value_token, false otherwise
*/
bool	is_value_token(const char *str)
{
	if (ft_strchr(JSON_TOKEN_CHARSETS, *str) == NULL)
		return (true);
	else
		return (false);
}
