/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_box_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:10:03 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/11 11:25:04 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material_box.h"
#include "define.h"

int	material_box_init(t_material_box *material_box)
{
	material_box->materials[0].k_ambient = 0.4;
	material_box->materials[0].k_diffuse = 0.4;
	material_box->materials[0].k_specular = 0.4;
	material_box->materials[0].k_shininess = 0.3;
	material_box->materials[0].is_reflective = false;
	material_box->materials[0].k_reflect = 0.1;
	material_box->materials[1].k_ambient = 0.4;
	material_box->materials[1].k_diffuse = 0.4;
	material_box->materials[1].k_specular = 0.4;
	material_box->materials[1].k_shininess = 0.3;
	material_box->materials[1].is_reflective = true;
	material_box->materials[1].k_reflect = 0.3;
	material_box->materials[2].k_ambient = 0.4;
	material_box->materials[2].k_diffuse = 0.4;
	material_box->materials[2].k_specular = 0.4;
	material_box->materials[2].k_shininess = 0.3;
	material_box->materials[2].is_reflective = true;
	material_box->materials[2].k_reflect = 0.3;
	return (SUCCESS);
}
//material_box_set_metal(&material_box->materials[0]);
//material_box_set_glass(&material_box->materials[1]);
//material_box_set_plastic(&material_box->materials[2]);
