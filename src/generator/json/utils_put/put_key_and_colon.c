/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_key_and_colon.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:25:56 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/27 20:14:51 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"

void	put_key_and_colon(t_dict *dict, int fd)
{
	ft_putchar_fd(KEY, fd);
	ft_putstr_fd(dict->key, fd);
	ft_putchar_fd(KEY, fd);
	ft_putstr_fd(GENERATOR_KEY_VALUE_SEPARATOR, fd);
}
