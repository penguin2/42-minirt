/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_parse.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:39:58 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/14 19:06:11 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_PARSE_H
# define MESSAGE_PARSE_H

// WARNING
# define WARNING_NORMALIZED "I normalized the vector as it wasn't already"
# define WARNING_FOV_IS_0 "Adjusted fov to 1 due to a 0 input"
# define WARNING_FOV_IS_180 "Adjusted fov to 179 due to a 180 input"
# define WARNING_SPOT_COLORS "Light color is invalid, so I set white color"

// ERROR
# define ARGC_IS_NOT_EQUAL_2 "argc != 2"
# define INVALID_FILE_EXTENSION "The file extension is invalid"
# define NOT_JSON_FORMAT "json format"
# define NO_TOKEN "json token is None"
# define JSON_FILE_IS_EMPTY "Json file is empty"

# define INVALID_PARAMETERS "parameters are invalid"
# define INVALID_VECTOR "The vector parameters are invalid"
# define INVALID_COLORS "The colors parameters are invalid"
# define INVALID_REQUIRED_OBJECT "The number of required objects is invalid"
# define OUTSIDE_THE_RANGE "Value is outside the range of upper or lower limit"
# define ATOF_FAILD "Doesn't conform to atof format or exceeds precision limit"
# define VECTOR_TOO_SMALL "The vector parameters are too small"
# define INVALID_BOOLEAN "parameter is not boolean"
# define VERTEXES_IS_STRAIGHT_LINE "triangle Vertexes is straight line"

#endif
