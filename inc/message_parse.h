/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_parse.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:39:58 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/10 10:17:29 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_PARSE_H
# define MESSAGE_PARSE_H

//// WARNING
# define WARNING_NORMALIZED "I normalized the vector as it wasn't already"
# define WARNING_FOV_IS_0 "Adjusted fov to 1 due to a 0 input"
# define WARNING_FOV_IS_180 "Adjusted fov to 179 due to a 180 input"
# define WARNING_LIGHT_COLORS "Light color is invalid, so I set white color"
# define WARNING_REACH_LIMIT "Reach double limit, so I set double limit value"

//// ERROR
// tokenize
# define ARGC_IS_NOT_EQUAL_2 "argc != 2"
# define INVALID_FILE_EXTENSION "The file extension is invalid"
# define NOT_JSON_FORMAT "json format"
# define NO_TOKEN "json token is None"
# define JSON_FILE_IS_EMPTY "Json file is empty"
# define JSON_DICT_KEY_DUPLICATE "Json dict key is duplicate"

// json parse
# define INVALID_PARAMETERS "parameters are invalid"
# define INVALID_VECTOR "The vector parameters are invalid"
# define INVALID_COLORS "The colors parameters are invalid"
# define INVALID_REQUIRED_OBJECT "The number of required objects is invalid"
# define INVALID_FILENAME "images for texture or bump may be inappropriate"
# define OUTSIDE_THE_RANGE "Value is outside the range of upper or lower limit"
# define ATOF_FAILD "Doesn't conform to atof format or exceeds precision limit"
# define VECTOR_TOO_SMALL "The vector parameters are too small"
# define INVALID_BOOLEAN "parameter is not boolean"
# define VERTEXES_IS_STRAIGHT_LINE "triangle Vertexes is straight line"

// rt parse
# define SPOT_LIGHT_DUPLICATE "[mandatory only] Light are duplicate"
# define RT_TR_OR_QD "[mandatory only] tr or qd identifer is invalid"
# define RT_OMITTED_KEY "[mandatory only] Option is invalid in the mandatory"
# define RT_IDENTIFER "Object identifier does not match rt file format"
# define RT_PARAMETER_SIZE "Object parameter size is invalid"
# define RT_OPTION_PARAMETER_FMT "Optional parameters format is [-- ID PARAM]"
# define RT_OPTION_IDENTIFER_INVALID "Optional parameter is invalid"
# define RT_OPTION_DUPLICATE "Optional parameters are duplicate"
# define RT_CHECKERBOARD "Checkerboard is only [sphere, plane, cylinder]"

#endif
