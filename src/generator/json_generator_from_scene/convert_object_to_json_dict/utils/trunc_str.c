/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trunc_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:20:35 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/14 23:16:25 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	trunc_str(char *str)
{
	char	*trunc_start_ptr;

	trunc_start_ptr = ft_strchr(str, '.');
	if (trunc_start_ptr == NULL)
		return ;
	str = &str[ft_strlen(str) - 1];
	while (trunc_start_ptr != str)
	{
		if (*str != '0')
			return ;
		*str-- = '\0';
	}
	if (trunc_start_ptr == str)
		*str = '\0';
}
