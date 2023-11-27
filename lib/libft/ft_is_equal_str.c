/* ************************************************************************** */
/*                                                        :::      ::::::::   */
/*   ft_is_equal_str.c                                  :+:      :+:    :+:   */
/*   ft_is_equal_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:23:28 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/05 18:48:14 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

bool	ft_is_equal_str(const char *s1, const char *s2)
{
	return (ft_strcmp(s1, s2) == 0);
}
