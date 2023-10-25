/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:39:58 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/25 18:50:15 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERATOR_H
# define GENERATOR_H

# include "parse.h"

# define INDENT_STR	"    "

// json
void	dict_generator(t_vla *list_of_dict, int fd, size_t nest_level);
void	json_generator(t_vla *json_object, int fd);
void	list_generator(t_vla *list, int fd, size_t nest_level);
void	put_indent_fd(int fd, size_t nest_level);

#endif
