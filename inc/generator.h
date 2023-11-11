/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:39:58 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/11 20:14:44 by rikeda           ###   ########.fr       */
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
void	json_generator_from_json_object(t_json_node *master_node,
			size_t nest_level,
			int fd);

// utils json_object -> json
void	put_open_brackets(t_json_node *master_node, int fd);
void	put_closing_brackets(t_json_node *master_node,
			size_t nest_level,
			int fd);

// rt_object -> json
void	json_generator_from_rt_object(t_vla *rt_objects, int fd);

// utils rt_object -> json
void	generator_rt_object(t_vla *rt_object, int fd);
bool	generator_ambient_object(t_vla *rt_object, int fd);
bool	generator_camera_object(t_vla *rt_object, int fd);
bool	generator_spot_object(t_vla *rt_object, int fd);
bool	generator_cylinder_object(t_vla *rt_object, int fd);
bool	generator_plane_object(t_vla *rt_object, int fd);
bool	generator_sphere_object(t_vla *rt_object, int fd);

void	put_key_and_list(const char *key,
			const char *value,
			bool is_with_comma,
			int fd);
void	put_key_and_value(const char *key,
			const char *value,
			bool is_with_comma,
			int fd);
void	put_options(t_vla *rt_object, bool is_with_comma, int fd);

// utils put
void	put_indent(size_t nest_level, int fd);
void	put_key_and_colon(const char *key_string, int fd);
void	put_value_separator(bool is_with_comma, size_t fd);

#endif
