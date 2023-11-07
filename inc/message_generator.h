/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_generator.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:39:58 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/07 20:45:12 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_GENERATOR_H
# define MESSAGE_GENERATOR_H

// WARNING
# define WARNING_NORMALIZED "I normalized the vector as it wasn't already"
# define WARNING_FOV_IS_0 "Adjusted fov to 0.1 due to a 0 input"
# define WARNING_FOV_IS_180 "Adjusted fov to 179.9 due to a 180 input"
# define WARNING_SPOT_COLORS "Light color is invalid, so I set white color"

// ERROR
# define INVALID_PARAMETERS "parameters are invalid"
# define INVALID_VECTOR "The vector parameters are invalid"
# define INVALID_COLORS "The colors parameters are invalid"
# define INVALID_REQUIRED_OBJECT "The number of required objects is invalid"
# define OUTSIDE_THE_RANGE "Value is outside the range of upper or lower limit"
# define ATOF_FAILD "Doesn't conform to atof format or exceeds precision limit"
# define VECTOR_TOO_SMALL "The vector parameters are too small"

#endif
