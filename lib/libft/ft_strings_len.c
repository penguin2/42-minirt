/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:35:18 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/06 13:35:31 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strings_len(const char **strings)
{
	size_t	idx;

	idx = 0;
	while (strings[idx] != NULL)
		idx++;
	return (idx);
}
