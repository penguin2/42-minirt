/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_strings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:36:30 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/12 14:39:36 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_free_strings(char **strings)
{
	size_t	idx;

	if (strings == NULL)
		return ;
	idx = 0;
	while (strings[idx] != NULL)
		free(strings[idx++]);
	free(strings);
}
