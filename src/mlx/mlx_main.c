/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:47:38 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/11 18:12:56 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "define.h"
#include <mlx.h>

int	mlx_main(t_scene *scene)
{
	void	*mlx_ptr;
	void	*mlx_wdw_ptr;

	mlx_ptr = mlx_init();
	mlx_wdw_ptr = mlx_new_window(mlx_ptr, WDW_WIDTH, WDW_HEIGHT, NAME);
	mlx_loop(mlx_ptr);
	(void)scene;
	return (SUCCESS);
}
