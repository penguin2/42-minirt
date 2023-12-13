/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:40:03 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/13 18:27:24 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdint.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	memory_size;

	if (count == 0 || size == 0)
		return (ft_calloc(1, 1));
	else if (SIZE_MAX / size < count)
		return (NULL);
	memory_size = count * size;
	ptr = malloc(memory_size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, memory_size);
	return (ptr);
}
