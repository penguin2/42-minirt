/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:39:58 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/02 20:24:24 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERATOR_H
# define GENERATOR_H

# include "parse.h"
# include "scene.h"
# include "libcolor.h"
# include "light.h"
# include "object.h"

# define INDENT_STR	"    "

# define GENERATOR_KEY_VALUE_SEPARATOR ": "
# define GENERATOR_VALUE_SEPARATOR ", "
# define GENERATOR_DICT_START "{"
# define GENERATOR_DICT_END "}"
# define GENERATOR_LIST_START "["
# define GENERATOR_LIST_END "]"
# define GENERATOR_COMMA ","

# define ATOF_LIMIT 15
# define ACCEPT_1_OR_OVER -1
# define UNLIMITED 0

# define ID_AMBIENT "A"
# define ID_CAMERA "C"
# define ID_SPOT "L"
# define ID_CYLINDER "cy"
# define ID_SPHERE "sp"
# define ID_PLANE "pl"

# define COLORS "colors"
# define BRIGHTNESS "brightness"
# define DIRECTION "orientation"
# define COORDINATES "coordinates"
# define FOV "fov"
# define NORMAL "normal"
# define DIAMETER "diameter"
# define HEIGHT "height"
# define AXIS "axis"

# define COEFFICIENT_NOT_SET 1
# define K_AMBIENT "coefficient-ambient"
# define K_DIFFUSE "coefficient-diffuse"
# define K_SPECULAR "coefficient-specular"
# define K_SHININESS "coefficient-shininess"

//// json
void		json_generator(t_json_node *master_node, size_t nest_level, int fd);

// utils json put fd
void		put_key_and_colon(t_json_node *json_node, int fd);
void		put_indent(size_t nest_level, int fd);
void		put_open_brackets(t_json_node *master_node, int fd);
void		put_value_separator(bool is_with_comma, size_t fd);
void		put_closing_brackets(t_json_node *master_node,
				size_t nest_level,
				int fd);

//// scene
int			json_object_to_scene(t_vla *json_object, t_scene *scene);
int			convert_json_object_to_camera(
				const t_json_node *node,
				t_camera *camera);

int			append_light_to_vla(
				const t_json_node *node,
				t_vla *vla,
				const char *identifier,
				int (*append_function)(const t_json_node *, t_vla *));

int			append_object_to_vla(
				const t_json_node *node,
				t_vla *vla,
				const char *identifier,
				int (*append_function)(const t_json_node *, t_vla *));

// lights
int			append_lights(const t_json_node *node, t_vla *lights);
int			append_spot(const t_json_node *node, t_vla *lights);
int			append_ambient(const t_json_node *node, t_vla *lights);

// objects
int			append_objects(const t_json_node *node, t_vla *lights);
int			append_plane(const t_json_node *node, t_vla *objects);
int			append_sphere(const t_json_node *node, t_vla *objects);
int			append_cylinder(const t_json_node *node, t_vla *objects);

// add additional parameters
int			add_additional_parameters(const t_json_node *json_node,
				t_object *object);
int			add_bump_map_parameter(const t_json_node *json_node,
				t_object *object);
int			add_image_map_parameter(const t_json_node *json_node,
				t_object *object);
int			add_material_parameter(const t_json_node *json_node,
				t_object *object);

// utils init scene 
int			list_to_color(const t_vla *list, t_color *color);

int			list_to_vec3(const t_vla *list,
				t_vec3 *vec3,
				double min,
				double max);

int			json_node_to_double(
				const t_json_node *node,
				double *dptr,
				double min,
				double max);

t_json_node	*select_json_node(const t_json_node *master_node, const char *key);
t_vla		*get_list(
				const t_json_node *node,
				const char *key,
				int accept_size);

bool		is_between_min_to_max(double n, double min, double max);
bool		is_only_value_node(const t_vla *list);
int			try_json_node_tof(const t_json_node *node, double *dptr);

#endif
