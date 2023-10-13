/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:39:37 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/13 17:00:34 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*new_str;

	if (s1 == NULL && s2 == NULL)
		new_str = ft_xcalloc(1, sizeof(char));
	else if (s1 == NULL)
		new_str = ft_strdup(s2);
	else if (s2 == NULL)
		new_str = ft_strdup(s1);
	else
	{
		size = ft_strlen(s1) + ft_strlen(s2);
		new_str = ft_xcalloc(size + 1, sizeof(char));
		ft_strcat(new_str, s1);
		ft_strcat(new_str, s2);
	}
	return (new_str);
}
