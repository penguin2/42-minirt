/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa_auto_adjust_when_over_limit.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:39:41 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/02 14:24:43 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"
#include "utils.h"
#include "message_parse.h"

char	*_create_double_limit_str(bool is_minus)
{
	char	*str;
	char	*str_top_ptr;
	size_t	idx;

	str = ft_xcalloc(sizeof(char), DOUBLE_LIMIT_DIGIT + 1 + is_minus);
	str_top_ptr = str;
	if (is_minus)
		*str++ = '-';
	idx = 0;
	while (idx < DOUBLE_LIMIT_DIGIT)
		str[idx++] = '9';
	return (str_top_ptr);
}

char	*ftoa_auto_adjust_when_over_limit(double n)
{
	char	*str;

	str = ft_ftoa(n, DOUBLE_LIMIT_DIGIT);
	if (str == NULL)
	{
		print_warning(WARNING_REACH_LIMIT);
		str = _create_double_limit_str(n < 0);
	}
	return (str);
}
