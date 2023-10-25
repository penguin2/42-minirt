/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:39:58 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/25 20:11:43 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERATOR_H
# define GENERATOR_H

# include "parse.h"

# define INDENT_STR	"	"

# define GENERATOR_KEY_VALUE_SEPARATOR ": "
# define GENERATOR_VALUE_VALUE_SEPARATOR ", "
# define GENERATOR_DICT_START "{"
# define GENERATOR_DICT_END "}"
# define GENERATOR_LIST_START "["
# define GENERATOR_LIST_END "]"
# define GENERATOR_COMMA ","

// json
void	dict_generator(t_vla *list_of_dict, int fd, size_t nest_level);
void	json_generator(t_vla *json_object, int fd);
void	list_generator(t_vla *list, int fd, size_t nest_level);
void	put_indent_fd(int fd, size_t nest_level);

#endif
