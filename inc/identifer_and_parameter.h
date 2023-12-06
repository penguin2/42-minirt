/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifer_and_parameter.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:24:15 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/06 17:06:10 by taekklee         ###   ########.fr       */
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
# define ID_TRIANGLE "tr"
# define ID_QUADRIC "qd"

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
# define VERTEX1 "vertex1"
# define VERTEX2 "vertex2"
# define VERTEX3 "vertex3"

// option parameters
# define K_AMBIENT_OMITTED "amb"
# define K_DIFFUSE_OMITTED "dif"
# define K_SPECULAR_OMITTED "spc"
# define K_SHININESS_OMITTED "shi"
# define K_REFLECT_OMITTED "rfl"
# define BUMP_MAP_OMITTED "bmp"
# define TEXTURE_MAP_OMITTED "tex"
# define CHECKERBOARD_OMITTED "chk"

# define K_AMBIENT "coefficient-ambient"
# define K_DIFFUSE "coefficient-diffuse"
# define K_SPECULAR "coefficient-specular"
# define K_SHININESS "coefficient-shininess"
# define K_REFLECT "coefficient-reflect"
# define IS_REFLECTIVE "is-reflective"

# define K_A "coefficient-a"
# define K_B "coefficient-b"
# define K_C "coefficient-c"
# define K_D "coefficient-d"
# define K_E "coefficient-e"

# define IS_CHECKERBOARD "checkerboard"
# define TEXTURE_MAP "texture-map"
# define BUMP_MAP "bump-map"
// mlx command operator
# define CMD_SAVE "Save"
# define CMD_EXIT "Exit"
# define CMD_DUMP "Dump"

#endif
