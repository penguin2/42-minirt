/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:05:46 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/13 17:53:00 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*unsigned_dst;
	const unsigned char	*unsigned_src;

	if (dst == src)
		return (dst);
	unsigned_dst = (unsigned char *)dst;
	unsigned_src = (const unsigned char *)src;
	while (0 < n)
	{
		*unsigned_dst++ = *unsigned_src++;
		n--;
	}
	return (dst);
}
