/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_non_charsets.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:08:34 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/16 19:10:19 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*ft_skip_non_charsets(const char *str, const char *charsets)
{
	while (*str != '\0')
	{
		if (ft_strchr(charsets, *str) != NULL)
			break ;
		str++;
	}
	return (str);
}
