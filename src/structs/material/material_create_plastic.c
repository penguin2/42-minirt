/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_create_plastic.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:39:40 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/11 13:41:51 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"

t_material	material_create_plastic(void)
{
	t_material	new;

	new.k_ambient = MATERIAL_AMBIENT_PLASTIC;
	new.k_diffuse = MATERIAL_DIFFUSE_PLASTIC;
	new.k_specular = MATERIAL_SPECULAR_PLASTIC;
	new.k_shininess = MATERIAL_SHININESS_PLASTIC;
	new.is_reflective = MATERIAL_IS_REFLECTIVE_PLASTIC;
	new.k_reflect = MATERIAL_REFLECT_PLASTIC;
	return (new);
}
