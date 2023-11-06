/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_key_and_colon.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:25:56 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/28 15:02:35 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"

void	put_key_and_colon(t_json_node *json_node, int fd)
{
	ft_putchar_fd(KEY, fd);
	ft_putstr_fd(json_node->key, fd);
	ft_putchar_fd(KEY, fd);
	ft_putstr_fd(GENERATOR_KEY_VALUE_SEPARATOR, fd);
}
