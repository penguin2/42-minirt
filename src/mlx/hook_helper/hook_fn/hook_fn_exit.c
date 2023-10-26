/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_fn_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:00:20 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/26 19:13:03 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	hook_fn_exit(void *_mlx_ptr, int keycode)
{
	(void)keycode;
	(void)_mlx_ptr;
	exit(EXIT_SUCCESS);
}
