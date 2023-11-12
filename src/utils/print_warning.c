/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_warning.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:47:05 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/10 18:26:41 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "define.h"
#include "utils.h"
#include <unistd.h>

void	print_warning(const char *message1)
{
	ft_putstr_fd(PRINT_COLOR_YELLOW, STDOUT_FILENO);
	ft_putstr_fd("Warning: ", STDOUT_FILENO);
	if (message1 != NULL)
		ft_putendl_fd(message1, STDOUT_FILENO);
	ft_putstr_fd(PRINT_COLOR_END, STDOUT_FILENO);
}
