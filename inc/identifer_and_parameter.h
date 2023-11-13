/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifer_and_parameter.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:24:15 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/13 15:02:32 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDENTIFER_AND_PARAMETER_H
# define IDENTIFER_AND_PARAMETER_H

// identifer
# define ID_AMBIENT "A"
# define ID_CAMERA "C"
# define ID_SPOT "L"
# define ID_CYLINDER "cy"
# define ID_SPHERE "sp"
# define ID_PLANE "pl"

// parameters
# define COLORS "colors"
# define BRIGHTNESS "brightness"
# define DIRECTION "orientation"
# define COORDINATES "coordinates"
# define FOV "fov"
# define NORMAL "normal"
# define DIAMETER "diameter"
# define HEIGHT "height"
# define AXIS "axis"

// option parameters
# define K_AMBIENT_OMITTED "amb"
# define K_DIFFUSE_OMITTED "dif"
# define K_SPECULAR_OMITTED "spc"
# define K_SHININESS_OMITTED "shi"
# define BUMP_MAP_OMITTED "bmp"
# define IMAGE_MAP_OMITTED "imp"

# define K_AMBIENT "coefficient-ambient"
# define K_DIFFUSE "coefficient-diffuse"
# define K_SPECULAR "coefficient-specular"
# define K_SHININESS "coefficient-shininess"

#endif
