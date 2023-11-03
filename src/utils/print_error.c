/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:47:05 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/03 16:03:04 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "define.h"
#include <unistd.h>

void	print_error(const char *message1)
{
	ft_putendl_fd(PRINT_COLOR_RED, STDERR_FILENO);
	ft_putendl_fd("Error", STDERR_FILENO);
	if (message1 != NULL)
		ft_putendl_fd(message1, STDERR_FILENO);
	ft_putendl_fd(PRINT_COLOR_END, STDERR_FILENO);
}
