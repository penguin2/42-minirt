/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_duplicate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:09:58 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/12 21:53:09 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stdbool.h>

bool	is_dupulicate(const char *str1, const char *str2)
{
	if (str1 == NULL || str2 == NULL)
		return (false);
	return (ft_is_equal_str(str1, str2));
}
