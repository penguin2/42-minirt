/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_ptr_hook_expose.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 02:02:21 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/07 02:03:01 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_ptr.h"

int	mlx_ptr_hook_expose(t_mlx_ptr *mlx_ptr)
{
	mlx_ptr->is_to_update = true;
	return (0);
}
