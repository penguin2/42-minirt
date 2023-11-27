/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_strings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:36:30 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/05 17:27:29 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_free_strings(void *ptr)
{
	size_t	idx;
	char	**strings;

	if (ptr == NULL)
		return ;
	strings = (char **)ptr;
	idx = 0;
	while (strings[idx] != NULL)
		free(strings[idx++]);
	free(strings);
}
