/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook_helper_set_hook.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 01:01:51 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/07 01:02:34 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_hook_helper.h"

void	mlx_hook_helper_set_hook(t_hook *hook, int identifier, void *handler)
{
	hook->identifier = identifier;
	hook->handler = handler;
}
