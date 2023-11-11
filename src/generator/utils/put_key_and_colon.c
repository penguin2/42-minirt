/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_key_and_colon.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:25:56 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/11 14:07:10 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"

void	put_key_and_colon(const char *key_string, int fd)
{
	ft_putchar_fd(KEY, fd);
	ft_putstr_fd(key_string, fd);
	ft_putchar_fd(KEY, fd);
	ft_putstr_fd(GENERATOR_KEY_VALUE_SEPARATOR, fd);
}
