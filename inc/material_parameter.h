/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_parameter.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:21:19 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/12 17:58:39 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_PARAMETER_H
# define MATERIAL_PARAMETER_H

# define MATERIAL_AMBIENT_DEFAULT (0.1)
# define MATERIAL_DIFFUSE_DEFAULT (0.5)
# define MATERIAL_SPECULAR_DEFAULT (0.5)
# define MATERIAL_SHININESS_DEFAULT (8.0)
# define MATERIAL_IS_REFLECTIVE_DEFAULT (0)
# define MATERIAL_REFLECT_DEFAULT (0.0)

# define MATERIAL_AMBIENT_METAL (0.2)
# define MATERIAL_DIFFUSE_METAL (0.8)
# define MATERIAL_SPECULAR_METAL (1.0)
# define MATERIAL_SHININESS_METAL (64.0)
# define MATERIAL_IS_REFLECTIVE_METAL (1)
# define MATERIAL_REFLECT_METAL (0.05)

# define MATERIAL_AMBIENT_PLASTIC (0.2)
# define MATERIAL_DIFFUSE_PLASTIC (0.6)
# define MATERIAL_SPECULAR_PLASTIC (0.0)
# define MATERIAL_SHININESS_PLASTIC (1.0)
# define MATERIAL_IS_REFLECTIVE_PLASTIC (0)
# define MATERIAL_REFLECT_PLASTIC (0.0)

# define MATERIAL_AMBIENT_MIRROR (0.2)
# define MATERIAL_DIFFUSE_MIRROR (0.3)
# define MATERIAL_SPECULAR_MIRROR (0.0)
# define MATERIAL_SHININESS_MIRROR (1.0)
# define MATERIAL_IS_REFLECTIVE_MIRROR (1)
# define MATERIAL_REFLECT_MIRROR (0.8)

#endif
