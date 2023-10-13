/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:05:54 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/13 17:52:46 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*unsigned_b;

	unsigned_b = (unsigned char *)b;
	while (0 < len)
	{
		*unsigned_b++ = c;
		len--;
	}
	return (b);
}
