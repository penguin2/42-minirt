/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:01:56 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/20 23:07:47 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANGE_H
# define RANGE_H

typedef struct s_range{
	double	start;
	double	end;
}	t_range;

t_range	range_create(double start, double end);

#endif
