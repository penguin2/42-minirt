/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_ptr_hook_destroy_notify.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 02:00:51 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/07 02:01:26 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_ptr.h"
#include <stdlib.h>

int	mlx_ptr_hook_destroy_notify(t_mlx_ptr *mlx_ptr)
{
	(void)mlx_ptr;
	exit(EXIT_SUCCESS);
}
