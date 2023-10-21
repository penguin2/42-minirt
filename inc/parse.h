/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:39:58 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/25 14:50:17 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "libft.h"
# include <stddef.h>
# include <libft.h>

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

enum e_stat
{
	IN_DICT,
	IN_LIST,
	END,
};

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
void	json_object_free(t_vla *json_object);

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

// statmachine
int		stat_dict_start(t_vla *token, t_vla *stack, size_t idx, int stat);
int		stat_dict_end(t_vla *token, t_vla *stack, size_t idx, int stat);
int		stat_list_start(t_vla *token, t_vla *stack, size_t idx, int stat);
int		stat_list_end(t_vla *token, t_vla *stack, size_t idx, int stat);
int		stat_comma(t_vla *token, t_vla *stack, size_t idx, int stat);
int		stat_colon(t_vla *token, t_vla *stack, size_t idx, int stat);
int		stat_key(t_vla *token, t_vla *stack, size_t idx, int stat);
int		stat_value(t_vla *token, t_vla *stack, size_t idx, int stat);

// statmachine utils
bool	is_value_token(const char *str);
bool	is_stat_closed(t_vla *stack, int open_char);
int		check_stat_end(t_vla *token, size_t idx, int stat);
int		get_stat(t_vla *stack);

// dict
t_dict	*dict_new(const char *key, void *value);
void	dict_free(t_dict *dict, void (free_value)(void *));

// node
t_node	*node_new(void *content, t_node_type type);
void	node_free(t_node *node, void (free_content)(void *));

// generator
void	dict_generator(t_vla *list_of_dict, int fd, size_t nest_level);
void	json_generator(t_vla *json_object, int fd);
void	list_generator(t_vla *list, int fd, size_t nest_level);
void	put_indent_fd(int fd, size_t nest_level);

char	*get_all_chars_in_file(int fd);

//// json parser

// json file to token
t_vla	*convert_json_to_token(const char *file);
int		check_token(t_vla *token);
t_vla	*tokenize(const char *str);

// token to json object
t_vla	*convert_token_to_json_object(t_vla *token);
t_vla	*prepere_json_object(t_vla *token);
void	convert_token_to_list(t_vla *json_object, size_t open_idx, size_t size);
void	convert_token_to_dict(t_vla *json_object, size_t open_idx, size_t size);

// statmachine
int		stat_dict_start(t_vla *token, t_vla *stack, size_t idx, int stat);
int		stat_dict_end(t_vla *token, t_vla *stack, size_t idx, int stat);
int		stat_list_start(t_vla *token, t_vla *stack, size_t idx, int stat);
int		stat_list_end(t_vla *token, t_vla *stack, size_t idx, int stat);
int		stat_comma(t_vla *token, t_vla *stack, size_t idx, int stat);
int		stat_colon(t_vla *token, t_vla *stack, size_t idx, int stat);
int		stat_key(t_vla *token, t_vla *stack, size_t idx, int stat);
int		stat_value(t_vla *token, t_vla *stack, size_t idx, int stat);

// statmachine utils
bool	is_value_token(const char *str);
bool	is_closed(t_vla *stack, int open_char);
int		check_stat_end(t_vla *token, size_t idx, int stat);
int		get_stat(t_vla *stack);

// dict
t_dict	*dict_new(const char *key, void *value);
void	dict_free(t_dict *dict, void (free_value)(void *));

// node
t_node	*node_new(void *content, t_node_type type);
void	node_free(t_node *node, void (free_content)(void *));

char	*get_all_chars_in_file(int fd);

t_vla	*convert_json_to_token(const char *file);
int		check_json_token(t_vla *token);
t_vla	*tokenize(const char *str);

int		stat_get(t_vla *stack);
int		stat_check_end(t_vla *token, size_t idx, int stat);
int		stat_dict_start(t_vla *token, t_vla *stack, size_t idx, int stat);
int		stat_dict_end(t_vla *token, t_vla *stack, size_t idx, int stat);
int		stat_list_start(t_vla *token, t_vla *stack, size_t idx, int stat);
int		stat_list_end(t_vla *token, t_vla *stack, size_t idx, int stat);
int		stat_comma(t_vla *token, t_vla *stack, size_t idx, int stat);
int		stat_colon(t_vla *token, t_vla *stack, size_t idx, int stat);
int		stat_key(t_vla *token, t_vla *stack, size_t idx, int stat);
int		stat_value(t_vla *token, t_vla *stack, size_t idx, int stat);
bool	is_value_token(const char *str);
bool	is_closed(t_vla *stack, int open_char);

t_dict	*dict_new(const char *key, void *value, int value_type);
void	dict_free(t_dict *dict, void (free_value)(void *));

#endif
