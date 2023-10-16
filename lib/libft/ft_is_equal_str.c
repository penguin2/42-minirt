/* ************************************************************************** */
/*                                                        :::      ::::::::   */
/*   ft_is_equal_str.c                                  :+:      :+:    :+:   */
/*   ft_is_equal_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:23:28 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/16 18:53:16 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

static int	_ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

bool	ft_is_equal_str(const char *s1, const char *s2)
{
	return (_ft_strcmp(s1, s2) == 0);
}
