/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:21:31 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/13 17:24:26 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrstr(const char *text, const char *pattern)
{
	size_t	pattern_len;
	char	*str_ptr;

	str_ptr = NULL;
	if (*pattern == '\0')
		return ((char *)text);
	pattern_len = ft_strlen(pattern);
	while (*text != '\0')
	{
		if (*text == *pattern && ft_is_equal_str_n(text, pattern, pattern_len))
			str_ptr = (char *)text;
		text++;
	}
	return (str_ptr);
}
