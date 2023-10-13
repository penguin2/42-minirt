/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_equal_str_n.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:03:16 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/13 17:50:17 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	_ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	idx;

	if (n == 0)
		return (0);
	idx = 0;
	while (idx < n)
	{
		if ((s1[idx] != s2[idx]) || (s1[idx] == '\0' || s2[idx] == '\0'))
			return (s1[idx] - s2[idx]);
		idx++;
	}
	return (0);
}

bool	ft_is_equal_str_n(const char *s1, const char *s2, size_t n)
{
	return (_ft_strncmp(s1, s2, n) == 0);
}
