/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:27:16 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/13 17:58:24 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_n(const char *str, size_t n)
{
	char	*new_str;

	new_str = (char *)ft_xcalloc(n + 1, sizeof(char));
	ft_strlcpy(new_str, str, n + 1);
	return (new_str);
}
