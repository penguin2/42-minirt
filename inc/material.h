/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:43:31 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/13 18:14:32 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

# include <stdbool.h>

typedef struct s_material{
	double	k_ambient;
	double	k_diffuse;
	double	k_specular;
	double	k_shininess;
	bool	is_reflective;
	double	k_reflect;
}	t_material;

t_material	material_create(
				double k_ambient,
				double k_diffuse,
				double k_specular,
				double k_shininess
				);

#endif
