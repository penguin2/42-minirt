/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:42:23 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/13 16:51:24 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new_str;
	size_t	size;

	size = ft_strlen(s1);
	new_str = (char *)ft_xcalloc(size + 1, sizeof(char));
	ft_strlcpy(new_str, s1, size + 1);
	return (new_str);
}
