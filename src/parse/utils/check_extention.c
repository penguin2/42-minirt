/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extention.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:24:02 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/13 19:22:14 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "libft.h"

int	check_extention(const char *file, const char *extention)
{
	char	*extention_start;

	if (ft_strlen(file) == ft_strlen(extention))
		return (ERROR);
	extention_start = ft_strrstr(file, extention);
	if (extention_start == NULL)
		return (ERROR);
	else if (!ft_is_equal_str(extention, extention_start))
		return (ERROR);
	else if (*(--extention_start) == '/')
		return (ERROR);
	else
		return (SUCCESS);
}
