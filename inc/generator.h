/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:39:58 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/15 16:54:33 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERATOR_H
# define GENERATOR_H

# include "parse.h"
# include "libcolor.h"
# include "light.h"
# include "object.h"
# include <float.h>

# define INDENT_STR	"    "
# define GENERATOR_KEY_VALUE_SEPARATOR ": "
# define GENERATOR_VALUE_SEPARATOR ", "
# define GENERATOR_DICT_START "{"
# define GENERATOR_DICT_END "}"
# define GENERATOR_LIST_START "["
# define GENERATOR_LIST_END "]"
# define GENERATOR_COMMA ","

# define RT_VECTOR_SEPARATOR ","

//// json_object -> json
void		json_generator_from_json_object(t_json_node *master_node,
				size_t nest_level,
				int fd);

// utils json_object -> json
void		put_open_brackets(t_json_node *master_node, int fd);
void		put_closing_brackets(t_json_node *master_node,
				size_t nest_level,
				int fd);

//// rt_object -> json
void		json_generator_from_rt_objects_array(t_vla *rt_objects, int fd);

// utils rt_object -> json
void		generator_rt_object(t_vla *rt_object, int fd);
void		generator_ambient_object(t_vla *ambient, int fd);
void		generator_camera_object(t_vla *camera, int fd);
void		generator_spot_object(t_vla *spot, int fd);
void		generator_cylinder_object(t_vla *cylinder, int fd);
void		generator_plane_object(t_vla *plane, int fd);
void		generator_sphere_object(t_vla *sphere, int fd);
void		generator_triangle_object(t_vla *triangle, int fd);
void		generator_quadric_object(t_vla *quadric, int fd);

void		put_key_and_list(const char *key,
				const char *value,
				bool is_with_comma,
				int fd);
void		put_key_and_value(const char *key,
				const char *value,
				bool is_with_comma,
				int fd);
void		put_options(t_vla *rt_object, int fd);

// utils put
void		put_indent(size_t nest_level, int fd);
void		put_key_and_colon(const char *key_string, int fd);
void		put_value_separator(bool is_with_comma, size_t fd);

//// scene -> json_object
void		json_generator_from_scene(t_scene *scene, int fd);
void		json_dict_generator_from_camera(t_camera *camera, t_vla *dict);
void		json_dict_generator_from_lights(t_vla *lights, t_vla *dict);
void		json_dict_generator_from_objects(t_vla *objects, t_vla *dict);
t_json_node	*convert_camera_to_camera_dict(t_camera *camera);
t_json_node	*convert_lights_to_json_dict(
				t_vla *lights,
				const char *identifer,
				t_light_id light_id,
				t_vla *(*generator)(t_light *));
t_json_node	*convert_objects_to_json_dict(
				t_vla *objects,
				const char *identifer,
				t_object_id object_id,
				t_vla *(*generator)(t_object *));

t_vla		*json_ambient_generator(t_light *light);
t_vla		*json_spot_generator(t_light *light);
t_vla		*sphere_generator(t_object	*object);
t_vla		*plane_generator(t_object *object);
t_vla		*cylinder_generator(t_object *object);
t_vla		*triangle_generator(t_object *object);
t_vla		*quadric_generator(t_object *object);

// utils
t_json_node	*color_to_json_list_node(const t_color *color, const char *key);
t_json_node	*vec3_to_json_list_node(const t_vec3 *vec, const char *key);
t_json_node	*double_to_json_value_node(double n, const char *key);
t_json_node	*bool_to_json_value_node(bool true_or_false, const char *key);
char		*ftoa_auto_adjust(double n);
double		round_to_digit(double n, int limit_digit);
void		trunc_str(char *str);

void		append_material_parameters_node(
				t_vla *json_obj,
				t_material material);
void		append_ppm_reader(
				t_vla *json_obj,
				const t_ppm_reader *ppm_reader,
				const char *key);

#endif
