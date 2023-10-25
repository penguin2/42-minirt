/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:39:58 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/25 18:33:16 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "libft.h"
# include <stddef.h>

# define NOT_EQUAL_EXTENSITON "Error: File is not equal extension"
# define NOT_JSON_FORMAT "Error: json format"
# define NO_TOKEN "Error: json token is None"

# define INDENT_STR	"    "

# define JSON_SPACE_CHARSETS " \t\n"
# define JSON_TOKEN_CHARSETS "{}[]:,"
# define JSON_SPACE_AND_TOKEN_CHARSETS "{}[]:, \t\n\""
# define BRACKETS 2
# define SIZE_OF_DICT_TOKEN 4

# define OPEN_BRACKETS 0
# define CLOSING_BRACKETS 1
# define PATTERN_NO_CONTENT_IN_DICT 1

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

typedef struct s_node
{
	void		*content;
	t_node_type	type;
}	t_node;

typedef struct s_dict
{
	char	*key;
	void	*value;
}	t_dict;

t_vla	*convert_json_to_json_object(const char *file);

// utils
int		check_extension(const char *file, const char *extension);
char	*delete_commentout(const char *str, const char *commentout_str);
int		try_atof_limit(const char *nptr, double *dptr, size_t limit);
char	*get_all_chars_in_file(int fd);
int		try_open_file(const char *file, const char *extension);

// json -> token
t_vla	*convert_json_to_token(const char *file);
int		check_token(t_vla *token);
t_vla	*tokenize(const char *str);

// token -> json_object
t_vla	*convert_token_to_json_object(t_vla *token);
t_vla	*prepere_json_object(t_vla *token);
void	convert_token_to_list(t_vla *json_object, size_t open_idx, size_t size);
void	convert_token_to_dict(t_vla *json_object, size_t open_idx, size_t size);

// statemachine
int		state_dict_start(t_vla *token, t_vla *stack, size_t idx, int state);
int		state_dict_end(t_vla *token, t_vla *stack, size_t idx, int state);
int		state_list_start(t_vla *token, t_vla *stack, size_t idx, int state);
int		state_list_end(t_vla *token, t_vla *stack, size_t idx, int state);
int		state_comma(t_vla *token, t_vla *stack, size_t idx, int state);
int		state_colon(t_vla *token, t_vla *stack, size_t idx, int state);
int		state_key(t_vla *token, t_vla *stack, size_t idx, int state);
int		state_value(t_vla *token, t_vla *stack, size_t idx, int state);

// statemachine utils
bool	is_value_token(const char *str);
bool	is_state_closed(t_vla *stack, int open_char);
int		check_state_end(t_vla *token, size_t idx, int state);
int		get_state(t_vla *stack);

// dict
t_dict	*dict_new(const char *key, void *value);
void	dict_free(t_dict *dict, void (free_value)(void *));

// node
t_node	*node_new(void *content, t_node_type type);
void	node_free(t_node *node, void (free_content)(void *));

// free json object
void	free_dict_of_json_object(t_vla *list_of_dict);
void	free_json_object(t_vla *json_object);
void	free_list_of_json_object(t_vla *list);

#endif
