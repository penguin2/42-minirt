/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_double_quotes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 22:19:50 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/28 22:25:16 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*remove_double_quotes(const char *double_quoted_str)
{
	size_t	size_without_double_quotes;

	size_without_double_quotes = ft_strlen(double_quoted_str) - 2;
	return (ft_strndup(double_quoted_str + 1, size_without_double_quotes));
}
