/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook_helper_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:18:40 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/07 00:58:37 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "mlx_hook_helper.h"

int	mlx_hook_helper_init(t_mlx_hook_helper *mlx_hook_helper)
{
	mlx_hook_helper_init_key_press(mlx_hook_helper->hooks_key_press);
	mlx_hook_helper_init_key_release(mlx_hook_helper->hooks_key_release);
	mlx_hook_helper_init_button_press(mlx_hook_helper->hooks_button_press);
	mlx_hook_helper_init_button_release(mlx_hook_helper->hooks_button_release);
	return (SUCCESS);
}
