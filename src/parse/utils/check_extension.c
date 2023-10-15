/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extention.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:24:02 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/15 23:12:43 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "libft.h"

int	check_extension(const char *file, const char *extension)
{
	char	*extention_start;

	if (ft_strlen(file) == ft_strlen(extension))
		return (ERROR);
	extention_start = ft_strrstr(file, extension);
	if (extention_start == NULL)
		return (ERROR);
	else if (!ft_is_equal_str(extension, extention_start))
		return (ERROR);
	else if (*(--extention_start) == '/')
		return (ERROR);
	else
		return (SUCCESS);
}
