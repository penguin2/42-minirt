/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_commentout.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:15:37 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/24 15:49:43 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*delete_commentout(char *str, const char *commentout_str)
{
	const char	*commentout_start = ft_strstr(str, commentout_str);
	char		*new_str;

	if (commentout_start != NULL)
	{
		new_str = ft_strdup_n(str, (commentout_start - str));
		free(str);
		return (new_str);
	}
	else
		return (str);
}
