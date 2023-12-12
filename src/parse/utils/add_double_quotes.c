/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_double_quotes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:57:59 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/06 20:09:00 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*add_double_quotes(const char *src)
{
	size_t	size_with_double_quotes;
	char	*dst;

	size_with_double_quotes = ft_strlen(src) + 2;
	dst = ft_xcalloc(size_with_double_quotes + 1, sizeof(char));
	dst[0] = '\"';
	ft_memcpy(dst + 1, src, size_with_double_quotes - 2);
	dst[size_with_double_quotes - 1] = '\"';
	dst[size_with_double_quotes] = '\0';
	return (dst);
}
