/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_box_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:10:03 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/12 17:59:25 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"
#include "material_box.h"
#include "define.h"

int	material_box_init(t_material_box *material_box)
{
	material_box->next_idx = 0;
	material_box->materials[0] = material_create_metal();
	material_box->materials[1] = material_create_plastic();
	material_box->materials[2] = material_create_mirror();
	return (SUCCESS);
}
