/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_fn_exit_cmd_mode.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:57:26 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/04 18:04:39 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_command_mode.h"

void	hook_fn_exit_cmd_mode(t_mlx_ptr *mlx_ptr, int keycode)
{
	(void)keycode;
	exit_cmd_mode(mlx_ptr);
}
