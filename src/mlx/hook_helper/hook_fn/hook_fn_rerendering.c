/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_fn_rerendering.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:00:20 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/06 19:19:28 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_hook_helper.h"
#include "mlx_ptr.h"
#include <stdlib.h>

void	hook_fn_rerendering(t_mlx_ptr *mlx_ptr, int keycode)
{
	(void)keycode;
	mlx_ptr->is_to_update = true;
}
