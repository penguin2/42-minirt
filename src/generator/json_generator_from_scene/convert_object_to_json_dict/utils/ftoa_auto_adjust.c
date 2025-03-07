/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa_auto_adjust.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:39:41 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/17 20:01:40 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"
#include "parse.h"
#include "utils.h"
#include "message_parse.h"

static char	*_create_double_limit_str(bool is_minus)
{
	char	*str;
	char	*str_top_ptr;
	size_t	idx;

	str = ft_xcalloc(DOUBLE_LIMIT_DIGIT + 1 + is_minus, sizeof(char));
	str_top_ptr = str;
	if (is_minus)
		*str++ = '-';
	idx = 0;
	while (idx < DOUBLE_LIMIT_DIGIT)
		str[idx++] = '9';
	return (str_top_ptr);
}

char	*ftoa_auto_adjust(double n)
{
	char	*str;

	n = round_to_digit(n, DOUBLE_LIMIT_DIGIT);
	str = ft_ftoa(n, DOUBLE_LIMIT_DIGIT);
	if (str == NULL)
	{
		print_warning(WARNING_REACH_LIMIT);
		str = _create_double_limit_str(n < 0);
	}
	trunc_str(str);
	return (str);
}
