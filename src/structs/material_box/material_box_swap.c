/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_box_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:34:54 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/11 12:38:15 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "material_box.h"

int	material_box_swap(t_material_box *material_box, t_material *target)
{
	t_material	tmp;

	if (material_box->next_idx >= MATERIAL_BOX_SIZE)
		return (ERROR);
	tmp = *target;
	*target = material_box->materials[material_box->next_idx];
	material_box->materials[material_box->next_idx] = tmp;
	if (++material_box->next_idx == MATERIAL_BOX_SIZE)
		material_box->next_idx = 0;
	return (SUCCESS);
}
