/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:24:02 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/25 14:32:02 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "libft.h"

int	check_extension(const char *file, const char *extension)
{
	char	*extension_start;

	if (ft_strlen(file) <= ft_strlen(extension))
		return (ERROR);
	extension_start = ft_strrstr(file, extension);
	if (extension_start == NULL
		|| !ft_is_equal_str(extension_start, extension)
		|| *(--extension_start) == '/')
		return (ERROR);
	else
		return (SUCCESS);
}
