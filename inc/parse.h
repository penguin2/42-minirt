/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:39:58 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/19 20:51:52 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <stddef.h>
# include <libft.h>

# define NOT_JSON_EXTENSITON "Error: File is not json extension"

# define BRACKETS 2

# define OPEN_BRACKETS 0
# define CLOSING_BRACKETS 1

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

// parse utils
int		check_extension(const char *file, const char *extension);
char	*del_commentout(const char *str, const char *commentout_str);
int		try_atof_limit(const char *nptr, double *dptr, size_t limit);
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

#endif
