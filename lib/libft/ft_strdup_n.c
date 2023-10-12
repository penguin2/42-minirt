/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:27:16 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/12 16:14:35 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_n(const char *str, size_t n)
{
	char	*new;

	new = (char *)ft_xcalloc(n + 1, sizeof(char));
	ft_strlcpy(new, str, n + 1);
	return (new);
}
