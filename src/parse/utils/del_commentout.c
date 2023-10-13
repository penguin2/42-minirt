/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_commentout.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:15:37 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/13 19:22:41 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*del_commentout(const char *str, const char *commentout_str)
{
	char	*commentout_start;

	commentout_start = ft_strstr(str, commentout_str);
	if (commentout_start != NULL)
		return (ft_strdup_n(str, (commentout_start - str)));
	else
		return (ft_strdup(str));
}
