/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:06:07 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/10 20:06:08 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>

void	ft_putstr_fd(const char *s, int fd)
{
	if (s != NULL)
	{
		if (write(fd, s, ft_strlen(s)) == -1)
			perror("Error");
	}
}
