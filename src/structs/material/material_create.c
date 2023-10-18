/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:34:03 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/12 16:34:59 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"

t_material	material_create(
				double k_ambient,
				double k_diffuse,
				double k_specular,
				double shininess
				)
{
	t_material	new;

	new.k_ambient = k_ambient;
	new.k_diffuse = k_diffuse;
	new.k_specular = k_specular;
	new.shininess = shininess;
	return (new);
}
