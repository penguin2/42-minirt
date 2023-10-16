/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_charsets.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:39:11 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/13 17:54:51 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*ft_skip_charsets(const char *str, const char *charsets)
{
	while (*str != '\0')
	{
		if (ft_strchr(charsets, *str) == NULL)
			break ;
		str++;
	}
	return (str);
}
