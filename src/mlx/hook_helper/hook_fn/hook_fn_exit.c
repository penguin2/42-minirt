/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_fn_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:00:20 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/26 22:22:50 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_hook_helper.h"
#include <stdlib.h>

void	hook_fn_exit(t_mlx_ptr *mlx_ptr, int keycode)
{
	(void)keycode;
	(void)mlx_ptr;
	exit(EXIT_SUCCESS);
}
