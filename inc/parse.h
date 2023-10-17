/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:39:58 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/17 21:30:34 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <stddef.h>
# include <libft.h>

# define NOT_JSON_EXTENSITON "Error: File is not json extension"

# define DICT 0
# define LIST 1

typedef struct s_dict
{
	char	*key;
	int		type;
	void	*value;
}	t_dict;

typedef enum e_json_stat
{
	START = 0,
	DICT_START,
	DICT_END,
	LIST_START,
	LIST_END,
	COLON,
	COMMA,
	KEY,
	VALUE,
	END,
}	t_json_stat;

int		check_extension(const char *file, const char *extension);
char	*del_commentout(const char *str, const char *commentout_str);
int		try_atof_limit(const char *nptr, double *dptr, size_t limit);

char	*get_all_chars_in_file(int fd);

t_vla	*change_json_to_token(const char *file);
int		check_json_token_nest(t_vla *token);
int		check_json_token(t_vla *token);
t_vla	*json_tokenizer(const char *str);

int		stat_get(t_vla *stack);
int		stat_check_end(t_vla *token, size_t idx);
int		stat_dict_start(t_vla *token, t_vla *stack, size_t idx, int stat);
int		stat_dict_end(t_vla *token, t_vla *stack, size_t idx, int stat);
int		stat_list_start(t_vla *token, t_vla *stack, size_t idx, int stat);
int		stat_list_end(t_vla *token, t_vla *stack, size_t idx, int stat);
int		stat_comma(t_vla *token, t_vla *stack, size_t idx, int stat);
int		stat_colon(t_vla *token, t_vla *stack, size_t idx, int stat);
int		stat_key(t_vla *token, t_vla *stack, size_t idx, int stat);
int		stat_value(t_vla *token, t_vla *stack, size_t idx, int stat);

#endif
