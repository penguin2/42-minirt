/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:43:23 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/12 16:54:12 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

typedef struct s_light{
	void	*ptr;
	void	(*free_ptr)(void *ptr);
}	t_light;

t_light	*light_new(
			void *ptr,
			void (*free_ptr)(void *ptr));
void	light_free(void *light);

#endif
