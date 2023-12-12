/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:39:58 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/12 14:16:32 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "libft.h"
# include "camera.h"
# include "light.h"
# include "ppm_reader.h"
# include "range.h"
# include "scene.h"
# include "object.h"
# include <stdbool.h>
# include <stddef.h>
# include <fcntl.h>

// extension
# define RT_EXTENSION ".rt"
# define JSON_EXTENSION ".json"
# define TXT_EXTENSION ".txt"

// tokenize
# define JSON_SPACE_CHARSETS " \t\n"
# define JSON_TOKEN_CHARSETS "{}[]:,"
# define JSON_SPACE_AND_TOKEN_CHARSETS "{}[]:, \t\n\""
# define JSON_KEY_CHARSETS "\""

// bool
# define TRUE_STRING "true"
# define TRUE_NUMBER "1"
# define FALSE_STRING "false"
# define FALSE_NUMBER "0"

// atof limit digit
# define DOUBLE_LIMIT_DIGIT 15

# define ACCEPT_1_OR_OVER -1

# define COEFFICIENT_NOT_SET 1

# define BRACKETS 2
# define SIZE_OF_DICT_TOKEN 4
# define OPEN_MODE 0644

# define OPEN_BRACKETS 0
# define CLOSING_BRACKETS 1

# define PATTERN_NO_CONTENT_IN_DICT 1

# define OPTION_START "--"
# define COMMENTOUT_STRING "#"
# define RT_SPACE_STR " \n	"

# define IDENTIFER_IDX 0
// option
# define OPTION_START_IDX 0
# define OPTION_KEY_IDX 1
# define OPTION_VAL_IDX 2

typedef enum e_required_max_size
{
	AMBIENT_MAX_SIZE = 3,
	CAMERA_MAX_SIZE = 4,
	SPOT_MAX_SIZE = 4,
	CYLINDER_MAX_SIZE = 6,
	PLANE_MAX_SIZE = 4,
	SPHERE_MAX_SIZE = 4,
	TRIANGLE_MAX_SIZE = 5,
	QUADRIC_MAX_SIZE = 8,
}	t_required_max_size;

typedef enum e_optional_max_size
{
	LIGHTS_OPTION_MAX_SIZE = 0,
	OBJECTS_OPTION_MAX_SIZE = 8,
}	t_optional_max_size;

typedef enum e_open_flag
{
	O_WRITE = O_CREAT | O_WRONLY | O_TRUNC,
	O_READ = O_RDONLY,
}	t_open_flag;

typedef enum e_state
{
	IN_DICT,
	IN_LIST,
	END,
}	t_state;

typedef enum e_node_type
{
	NODE_NO_TYPE,
	NODE_VALUE,
	NODE_DICT,
	NODE_LIST,
}	t_node_type;

typedef enum e_json_token_initials
{
	DICT_START = '{',
	LIST_START = '[',
	DICT_END = '}',
	LIST_END = ']',
	COLON = ':',
	COMMA = ',',
	KEY = '"',
}	t_json_token_initials;

typedef struct s_json_node
{
	t_node_type	type;
	char		*key;
	void		*value;
}	t_json_node;

typedef struct s_query
{
	const t_json_node	*json_node;
	const char			*key;
	void				*value;
	bool				is_required;
}	t_query;

//// json -> json_object
t_vla		*convert_json_to_json_object(const char *file);
void		sort_json_object(t_json_node *master_node);
int			check_duplicate_dict_key(t_json_node *master_node);
void		free_json_object(t_vla *json_object);

// utils
int			check_extension(const char *file, const char *extension);
char		*delete_commentout(const char *str, const char *commentout_str);
int			try_atof_limit(const char *nptr, double *dptr, size_t limit);
char		*get_next_removed_comment_line(int fd);
int			try_open_file(const char *file, const char *extension, int flag);
char		*convert_extension(const char *file,
				const char *old_extension,
				const char *new_extension);
bool		is_list_with_value_nodes(const t_json_node *node, size_t size);
bool		is_only_value_node(const t_vla *list);
bool		is_with_double_quotes(const char *str);
char		*remove_double_quotes(const char *double_quoted_str);
char		*add_double_quotes(const char *src);

// json -> token
t_vla		*convert_json_to_token(const char *file);
int			check_token(t_vla *token);
t_vla		*tokenize(const char *str);

// token -> json_object
t_vla		*convert_token_to_json_object(t_vla *token);
t_vla		*prepere_json_object(t_vla *token);
void		convert_token_to_list(t_vla *json_object,
				size_t open_idx,
				size_t size);
void		convert_token_to_dict(t_vla *json_object,
				size_t open_idx,
				size_t size);

// statemachine
int			state_dict_start(t_vla *token, t_vla *stack, size_t idx, int state);
int			state_dict_end(t_vla *token, t_vla *stack, size_t idx, int state);
int			state_list_start(t_vla *token, t_vla *stack, size_t idx, int state);
int			state_list_end(t_vla *token, t_vla *stack, size_t idx, int state);
int			state_comma(t_vla *token, t_vla *stack, size_t idx, int state);
int			state_colon(t_vla *token, t_vla *stack, size_t idx, int state);
int			state_key(t_vla *token, t_vla *stack, size_t idx, int state);
int			state_value(t_vla *token, t_vla *stack, size_t idx, int state);

// statemachine utils
bool		is_value_token(const char *str);
bool		is_state_closed(t_vla *stack, int c, int close_char);
int			check_state_end(t_vla *token, size_t idx, int state);
int			get_state(t_vla *stack);

// json node
t_json_node	*json_node_new(char *key, void *value, t_node_type type);
void		json_node_free(t_json_node *node, void (free_value)(void *));

//// json_object -> scene
int			json_object_to_scene(t_vla *json_object, t_scene *scene);
int			camera_init(const t_json_node *node, t_camera *camera);
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
int			append_triangle(const t_json_node *node, t_vla *objects);
int			append_quadric(const t_json_node *node, t_vla *objects);

// add parameters
int			add_object_color(const t_json_node *json_node, t_object *object);
int			add_light_color(const t_json_node *json_node, t_light *light);

int			add_additional_parameters(const t_json_node *json_node,
				t_object *object);
int			add_texture_map_parameter(const t_json_node *json_node,
				t_object *object);
int			add_bump_map_parameter(const t_json_node *json_node,
				t_object *object);
int			add_checkerboard_parameter(const t_json_node *json_node,
				t_object *object);
int			add_material_parameter(const t_json_node *json_node,
				t_object *object);

// utils init scene 
t_vla		*get_list(
				const t_json_node *node,
				const char *key,
				int accept_size);

bool		is_between_min_to_max(double n, double min, double max);
t_json_node	*select_json_node(const t_json_node *master_node, const char *key);
int			try_json_node_tof(const t_json_node *node, double *dptr);
int			try_vec3_unit(t_vec3 *vec);

// json_node -> bool, double ...
int			json_node_to_bool(
				const t_json_node *json_node, bool *val);
int			json_node_to_double(
				const t_json_node *node, t_range range, double *val);
int			json_node_to_vec3(
				const t_json_node *node, t_range range, t_vec3 *val);
int			json_node_to_color(
				const t_json_node *node, t_color *val);
int			json_node_to_string(const t_json_node *node, char **str);
int			json_node_to_ppm_reader(
				const t_json_node *node, t_ppm_reader **ptr);
// query
t_query		query_create(
				const t_json_node *json_node,
				const char *key,
				void *value,
				bool is_required);
int			query_set_double(t_query query, t_range range);
int			query_set_boolean(t_query query);
int			query_set_vec3(t_query query, t_range range);
int			query_set_color(t_query query);
int			query_set_ppm_reader(t_query query);

//// rt 
int			convert_rt_to_json(const char *file);
int			convert_rt_to_rt_objects_array(t_vla *rt_objects_array, int fd);
void		convert_rt_to_no_grouping_rt_objects(t_vla *no_grouping_rt_objects,
				int fd);
void		grouping_same_rt_objects(t_vla *no_grouping_rt_objects);

void		free_rt_objects_array(t_vla *rt_objects_array);
void		free_no_grouping_rt_objects(t_vla *no_grouping_rt_objects);

// utils
void		sort_no_grouping_rt_objects(t_vla *no_grouping_rt_objects);
void		sort_rt_object_options(const t_vla *rt_object);

int			check_rt_object_format(t_vla *no_grouping_rt_objects);
int			check_rt_object_option_format(const t_vla *rt_object);
int			check_duplicate_spot(t_vla *rt_objects_array);
int			check_size_of_parameters(const t_vla *rt_object,
				t_required_max_size required_parameters_max_size,
				t_optional_max_size optional_parameters_max_size);

bool		is_duplicate(const char *str1, const char *str2);
bool		is_option_key(const char *option_key, const char *identifer);

const char	*get_identifer_from_no_grouping_rt_objects(
				const t_vla *no_grouping_rt_objects,
				size_t idx);
const char	*get_identifer_from_rt_objects_array(
				const t_vla *rt_objects,
				size_t idx);

#endif
