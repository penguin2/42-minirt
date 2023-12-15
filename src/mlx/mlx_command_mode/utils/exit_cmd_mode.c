/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cmd_mode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:57:26 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/04 18:03:58 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_hook_helper.h"
#include "mlx_ptr.h"

void	exit_cmd_mode(t_mlx_ptr *mlx_ptr)
{
	mlx_ptr->mode = MLX_MODE_NORMAL;
	mlx_ptr->is_to_update = true;
}
