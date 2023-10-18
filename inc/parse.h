/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:39:58 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/18 14:44:04 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <stddef.h>
# include <libft.h>

# define NOT_JSON_EXTENSITON "Error: File is not json extension"

typedef struct s_dict
{
	char	*key;
	int		type;
	void	*value;
}	t_dict;

enum e_stat
{
	IN_DICT,
	IN_LIST,
	END,
};

int		check_extension(const char *file, const char *extension);
char	*del_commentout(const char *str, const char *commentout_str);
int		try_atof_limit(const char *nptr, double *dptr, size_t limit);

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

#endif
