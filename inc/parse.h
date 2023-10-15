/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:39:58 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/16 00:48:50 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <stddef.h>
# include <libft.h>

typedef struct s_dict
{
	char	*key;
	int		type;
	void	*value;
}	t_dict;

typedef enum e_json_value_type
{
	NOT_SET,
	NUMBER,
	BOOL,
	STRING,
	DICT,
	LIST,
}	t_json_value_type;

typedef enum e_json_stat
{
	START,
	DICT_START,
	LIST_END,
	LIST_START,
	DICT_END,
	COLON,
	COMMA,
	KEY,
	VALUE,
}	t_json_stat;

int		check_extension(const char *file, const char *extension);
char	*del_commentout(const char *str, const char *commentout_str);
int		try_atof_limit(const char *nptr, double *dptr, size_t limit);

char	*get_all_chars_in_file(int fd);
t_vla	*json_tokenizer(const char *str);

#endif
