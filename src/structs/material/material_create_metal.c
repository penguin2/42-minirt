/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_create_metal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:31:02 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/12 17:43:43 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"
#include "material_parameter.h"

t_material	material_create_metal(void)
{
	t_material	new;

	new.k_ambient = MATERIAL_AMBIENT_METAL;
	new.k_diffuse = MATERIAL_DIFFUSE_METAL;
	new.k_specular = MATERIAL_SPECULAR_METAL;
	new.k_shininess = MATERIAL_SHININESS_METAL;
	new.is_reflective = MATERIAL_IS_REFLECTIVE_METAL;
	new.k_reflect = MATERIAL_REFLECT_METAL;
	return (new);
}
