/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_create_glass.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:29:48 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/11 13:39:35 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"

t_material	material_create_glass(void)
{
	t_material	new;

	new.k_ambient = MATERIAL_AMBIENT_GLASS;
	new.k_diffuse = MATERIAL_DIFFUSE_GLASS;
	new.k_specular = MATERIAL_SPECULAR_GLASS;
	new.k_shininess = MATERIAL_SHININESS_GLASS;
	new.is_reflective = MATERIAL_IS_REFLECTIVE_GLASS;
	new.k_reflect = MATERIAL_REFLECT_GLASS;
	return (new);
}
