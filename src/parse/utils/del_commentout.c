/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_commentout.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:15:37 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/15 21:00:00 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*del_commentout(char *str, const char *commentout_str)
{
	const char	*commentout_start;
	char		*new_str;

	commentout_start = ft_strstr(str, commentout_str);
	if (commentout_start != NULL)
	{
		new_str = ft_strdup_n(str, (commentout_start - str));
		free(str);
		return (new_str);
	}
	else
		return (str);
}
