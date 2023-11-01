/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:27:16 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/25 18:46:50 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, size_t n)
{
	char	*new_str;

	new_str = (char *)ft_xcalloc(n + 1, sizeof(char));
	ft_strlcpy(new_str, str, n + 1);
	return (new_str);
}
