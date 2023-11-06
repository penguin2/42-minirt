/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook_helper_init_button_release.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:31:35 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/07 01:01:24 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_hook_helper.h"

void	mlx_hook_helper_init_button_release(t_hook *hooks_br)
{
	mlx_hook_helper_set_hook(
		hooks_br++, BUTTON_LEFT_X, hook_fn_set_button_left_off);
}
