/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_value_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 00:35:26 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/18 01:01:52 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	is_value_token(const char *str)
{
	if (ft_strchr("{}[]:,", *str) == NULL)
		return (true);
	else
		return (false);
}
