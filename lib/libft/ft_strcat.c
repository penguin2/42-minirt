/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:54:54 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/13 16:57:14 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strcat(char *dst, const char *src)
{
	size_t	idx;

	if (dst == NULL)
		return (NULL);
	else if (src == NULL)
		return (dst);
	idx = 0;
	while (dst[idx] != '\0')
		idx++;
	while (*src != '\0')
		dst[idx++] = *src++;
	return (dst);
}
