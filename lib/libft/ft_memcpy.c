/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:05:46 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/10 21:45:56 by rikeda           ###   ########.fr       */
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
	while (n-- > 0)
		*unsigned_dst++ = *unsigned_src++;
	return (dst);
}
