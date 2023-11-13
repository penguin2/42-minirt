/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:39:58 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/13 18:02:45 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "libft.h"
# include "camera.h"
# include "scene.h"
# include "object.h"
# include <stddef.h>

// tokenize
# define JSON_SPACE_CHARSETS " \t\n"
# define JSON_TOKEN_CHARSETS "{}[]:,"
# define JSON_SPACE_AND_TOKEN_CHARSETS "{}[]:, \t\n\""
# define JSON_KEY_CHARSETS "\""

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
# define K_AMBIENT "coefficient-ambient"
# define K_DIFFUSE "coefficient-diffuse"
# define K_SPECULAR "coefficient-specular"
# define K_SHININESS "coefficient-shininess"

// atof limit digit
# define DOUBLE_LIMIT_DIGIT 15

# define NO_LIMIT 0

# define ACCEPT_1_OR_OVER -1

# define COEFFICIENT_NOT_SET 1

# define BRACKETS 2
# define SIZE_OF_DICT_TOKEN 4

# define OPEN_BRACKETS 0
# define CLOSING_BRACKETS 1

# define PATTERN_NO_CONTENT_IN_DICT 1

# define MAX_COLOR_8BIT (255)

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

//// json -> json_object
t_vla		*convert_json_to_json_object(const char *file);
void		free_json_object(t_vla *json_object);

// utils
int			check_extension(const char *file, const char *extension);
char		*delete_commentout(const char *str, const char *commentout_str);
int			try_atof_limit(const char *nptr, double *dptr, size_t limit);
char		*get_all_chars_in_file(int fd);
int			try_open_file(const char *file, const char *extension);

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

// add parameters
int			add_color_parameter(const t_json_node *json_node, t_object *object);
int			add_additional_parameters(const t_json_node *json_node,
				t_object *object);
int			add_bump_map_parameter(const t_json_node *json_node,
				t_object *object);
int			add_image_map_parameter(const t_json_node *json_node,
				t_object *object);
int			add_material_parameter(const t_json_node *json_node,
				t_object *object);

// utils init scene 
t_vla		*get_list(
				const t_json_node *node,
				const char *key,
				int accept_size);

bool		is_between_min_to_max(double n, double min, double max);
int			json_node_to_double(
				const t_json_node *node,
				double *dptr,
				double min,
				double max);
int			list_to_color(const t_vla *list, t_color *color);
int			list_to_vec3(
				const t_vla *list,
				t_vec3 *vec3,
				double min,
				double max);
t_json_node	*select_json_node(const t_json_node *master_node, const char *key);
int			try_json_node_tof(const t_json_node *node, double *dptr);
int			try_vec3_unit(t_vec3 *vec);

#endif
