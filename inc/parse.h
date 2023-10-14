/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:39:58 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/14 18:57:13 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <stddef.h>

typedef struct s_dict
{
	char	*key;
	int		type;
	void	*value;
}	t_dict;

enum
{
	NOT_SET,
	NUMBER,
	BOOL,
	STRING,
	DICT,
	LIST,
};

int		check_extention(const char *file, const char *extention);
char	*del_commentout(const char *str, const char *commentout_str);
int		try_atof_limit(const char *nptr, double *dptr, size_t limit);
char	*try_ftoa_limit(double number, size_t limit);

#endif
