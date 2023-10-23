/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_fn_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:00:20 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/23 15:02:32 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include <stdlib.h>

void	hook_fn_exit(t_scene *scene)
{
	(void)scene;
	exit(EXIT_SUCCESS);
}
