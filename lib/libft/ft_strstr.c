/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:11:05 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/13 17:21:13 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *text, const char *pattern)
{
	size_t	pattern_len;

	if (*pattern == '\0')
		return ((char *)text);
	pattern_len = ft_strlen(pattern);
	while (*text != '\0')
	{
		if (*text == *pattern && ft_is_equal_str_n(text, pattern, pattern_len))
			return ((char *)text);
		text++;
	}
	return (NULL);
}
