/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_with_double_quotes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 22:11:04 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/28 22:45:51 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>
#include <stddef.h>

bool	is_with_double_quotes(const char *str)
{
	const size_t	len = ft_strlen(str);

	return (len >= 2
		&& str[0] == '"'
		&& str[len - 1] == '"');
}
