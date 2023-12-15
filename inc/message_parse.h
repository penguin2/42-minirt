/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_parse.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:39:58 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/14 17:34:09 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_PARSE_H
# define MESSAGE_PARSE_H

//// SUCCESS
# define CMD_SAVE_SUCCESS "Scene is saved!!"
# define CMD_DUMP_SUCCESS "Dump is success!!"

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
# define ATOF_FAILED "Doesn't conform to atof format or exceeds precision limit"
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
# define RT_OPTION_INVALID "Texture-map, Bump-map, Checkerboard options \
are only for [sphere, plane, cylinder]"

// command line parse
# define CMD_EMPTY "Command line is empty"
# define CMD_NOT_FOUND "Command is not found"
# define CMD_OPEN_FAILED "File open Failed!!"
# define CMD_INVALID_EXTENSION "File extension is invalid"
# define CMD_NOT_SELECT "Object not selected"
# define CMD_SELECTED "Selected object!!!"
# define CMD_SAVE_FAILED "Please understand format [save FILEPATH]"
# define CMD_SAVE_NOT_JSON "File extension is not json"
# define CMD_EXIT_FAILED "Please understand format [q]"
# define CMD_DUMP_FAILED "Please understand format [dump FILE_PATH]"
# define CMD_HELP_FAILED "Please understand format [help {HELP_OPTION}]"
# define CMD_HELP_OPEN_FAILED "help options will be displayed by [:help]"
# define CMD_MOD_FAILED "Please understand format [mod PARAMETERNAME VALUE]"
# define CMD_MOD_KEY_FAILED "Key is invalid"
# define CMD_MOD_VALUE_FAILED "Parameter is invalid"
# define CMD_DEL_FAILED "Please understand format [del]"

#endif
