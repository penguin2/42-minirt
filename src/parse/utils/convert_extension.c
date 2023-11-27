/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_extension.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:08:44 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/06 14:46:33 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*convert_extension(const char *file,
							const char *old_extension,
							const char *new_extension)
{
	const char	*extension_start = ft_strrstr(file, old_extension);
	char		*file_without_extension;
	char		*new_file_name;

	file_without_extension = ft_strndup(file, extension_start - file);
	new_file_name = ft_strjoin(file_without_extension, new_extension);
	free(file_without_extension);
	return (new_file_name);
}
