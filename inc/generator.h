/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:39:58 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/08 15:46:04 by rikeda           ###   ########.fr       */
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

void	json_generator_from_json_object(t_json_node *master_node,
			size_t nest_level,
			int fd);

// utils put
void	put_key_and_colon(t_json_node *json_node, int fd);
void	put_indent(size_t nest_level, int fd);
void	put_open_brackets(t_json_node *master_node, int fd);
void	put_value_separator(bool is_with_comma, size_t fd);
void	put_closing_brackets(t_json_node *master_node,
			size_t nest_level,
			int fd);

#endif
