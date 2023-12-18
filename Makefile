NAME			=	miniRT
NAME_BONUS		=	miniRT_bonus
BONUS			=	bonus

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
CFLAGS_BONUS	=	-Wall -Wextra -Werror -DMODE=1
PRE_OPT			=	-MMD -MP
LINKER_OPT 		=	-L$(MINILIBX_DIR) -lmlx -L/usr/X11/lib -lX11 -lXext -lm
INCLUDE			=	-I$(INC_DIR) -I$(MINILIBX_DIR) -I$(shell cd $(MINILIBX_DIR) && ./configure | head -n 1 | cut -d' ' -f9)

SRC_DIR			=	./src
OBJ_DIR			=	./obj
OBJ_BONUS_DIR	=	./obj_bonus
INC_DIR			=	./inc
LIB_DIR			=	./lib
MINILIBX_DIR	=	./minilibx
TEST_MAIN_DIR	=	./test_main


LIB_HEADER		=	$(LIB_DIR)/libcolor/libcolor.h \
					$(LIB_DIR)/libft/libft.h \
					$(LIB_DIR)/libgnl/libgnl.h \
					$(LIB_DIR)/libvec3/libvec3.h

LIB_HEADER_DIR	=	$(sort $(dir $(LIB_HEADER)))
INCLUDE			+=	$(patsubst %, -I./%, $(LIB_HEADER_DIR))
LIB_SRCS		=	$(LIB_DIR)/libcolor/color_add.c \
					$(LIB_DIR)/libcolor/color_black.c \
					$(LIB_DIR)/libcolor/color_cast.c \
					$(LIB_DIR)/libcolor/color_composite.c \
					$(LIB_DIR)/libcolor/color_create.c \
					$(LIB_DIR)/libcolor/color_create_by_int.c \
					$(LIB_DIR)/libcolor/color_mix.c \
					$(LIB_DIR)/libcolor/color_mul.c \
					$(LIB_DIR)/libcolor/color_white.c \
					$(LIB_DIR)/libft/ft_atof.c \
					$(LIB_DIR)/libft/ft_atoi.c \
					$(LIB_DIR)/libft/ft_calloc.c \
					$(LIB_DIR)/libft/ft_count_digit.c \
					$(LIB_DIR)/libft/ft_free_strings.c \
					$(LIB_DIR)/libft/ft_ftoa.c \
					$(LIB_DIR)/libft/ft_is_equal_str.c \
					$(LIB_DIR)/libft/ft_is_equal_str_n.c \
					$(LIB_DIR)/libft/ft_isdigit.c \
					$(LIB_DIR)/libft/ft_lltoa.c \
					$(LIB_DIR)/libft/ft_memcpy.c \
					$(LIB_DIR)/libft/ft_memset.c \
					$(LIB_DIR)/libft/ft_putchar_fd.c \
					$(LIB_DIR)/libft/ft_putendl_fd.c \
					$(LIB_DIR)/libft/ft_putstr_fd.c \
					$(LIB_DIR)/libft/ft_skip_charsets.c \
					$(LIB_DIR)/libft/ft_skip_non_charsets.c \
					$(LIB_DIR)/libft/ft_sort.c \
					$(LIB_DIR)/libft/ft_split.c \
					$(LIB_DIR)/libft/ft_split_keeping_delimiters.c \
					$(LIB_DIR)/libft/ft_strcat.c \
					$(LIB_DIR)/libft/ft_strchr.c \
					$(LIB_DIR)/libft/ft_strcmp.c \
					$(LIB_DIR)/libft/ft_strdup.c \
					$(LIB_DIR)/libft/ft_strings_len.c \
					$(LIB_DIR)/libft/ft_strjoin.c \
					$(LIB_DIR)/libft/ft_strlcpy.c \
					$(LIB_DIR)/libft/ft_strlen.c \
					$(LIB_DIR)/libft/ft_strndup.c \
					$(LIB_DIR)/libft/ft_strrstr.c \
					$(LIB_DIR)/libft/ft_strstr.c \
					$(LIB_DIR)/libft/ft_vla_append.c \
					$(LIB_DIR)/libft/ft_vla_free.c \
					$(LIB_DIR)/libft/ft_vla_init.c \
					$(LIB_DIR)/libft/ft_vla_new.c \
					$(LIB_DIR)/libft/ft_vla_pop.c \
					$(LIB_DIR)/libft/ft_xcalloc.c \
					$(LIB_DIR)/libgnl/get_next_line.c \
					$(LIB_DIR)/libgnl/reader_read.c \
					$(LIB_DIR)/libgnl/reader_utils.c \
					$(LIB_DIR)/libgnl/set_string.c \
					$(LIB_DIR)/libgnl/string_push_back.c \
					$(LIB_DIR)/libgnl/string_utils.c \
					$(LIB_DIR)/libvec3/vec3_add.c \
					$(LIB_DIR)/libvec3/vec3_create.c \
					$(LIB_DIR)/libvec3/vec3_cross.c \
					$(LIB_DIR)/libvec3/vec3_dot.c \
					$(LIB_DIR)/libvec3/vec3_len.c \
					$(LIB_DIR)/libvec3/vec3_len_squared.c \
					$(LIB_DIR)/libvec3/vec3_mul.c \
					$(LIB_DIR)/libvec3/vec3_projected.c \
					$(LIB_DIR)/libvec3/vec3_reflected.c \
					$(LIB_DIR)/libvec3/vec3_some_orthogonal.c \
					$(LIB_DIR)/libvec3/vec3_sub.c \
					$(LIB_DIR)/libvec3/vec3_unit.c \
					$(LIB_DIR)/libvec3/vec3_unit_x.c \
					$(LIB_DIR)/libvec3/vec3_unit_y.c \
					$(LIB_DIR)/libvec3/vec3_unit_z.c

LIB_OBJS		=	$(patsubst %.o, $(OBJ_DIR)/%.o, $(LIB_SRCS:.c=.o))
LIB_OBJS_BONUS	=	$(patsubst %.o, $(OBJ_BONUS_DIR)/%.o, $(LIB_SRCS:.c=.o))

SRCS			=	generator/json_generator_from_json_object/json_generator_from_json_object.c \
					generator/json_generator_from_json_object/utils_put/put_closing_brackets.c \
					generator/json_generator_from_json_object/utils_put/put_open_brackets.c \
					generator/json_generator_from_rt_objects_array/generator_rt_object/generator_ambient_object.c \
					generator/json_generator_from_rt_objects_array/generator_rt_object/generator_camera_object.c \
					generator/json_generator_from_rt_objects_array/generator_rt_object/generator_cylinder_object.c \
					generator/json_generator_from_rt_objects_array/generator_rt_object/generator_plane_object.c \
					generator/json_generator_from_rt_objects_array/generator_rt_object/generator_quadric.c \
					generator/json_generator_from_rt_objects_array/generator_rt_object/generator_rt_object.c \
					generator/json_generator_from_rt_objects_array/generator_rt_object/generator_sphere_object.c \
					generator/json_generator_from_rt_objects_array/generator_rt_object/generator_spot_object.c \
					generator/json_generator_from_rt_objects_array/generator_rt_object/generator_triangle.c \
					generator/json_generator_from_rt_objects_array/json_generator_from_rt_objects_array.c \
					generator/json_generator_from_rt_objects_array/utils_put/put_key_and_list.c \
					generator/json_generator_from_rt_objects_array/utils_put/put_key_and_value.c \
					generator/json_generator_from_rt_objects_array/utils_put/put_options.c \
					generator/json_generator_from_scene/convert_object_to_json_dict/convert_lights_to_json_dict/convert_lights_to_json_dict.c \
					generator/json_generator_from_scene/convert_object_to_json_dict/convert_lights_to_json_dict/json_ambient_generator.c \
					generator/json_generator_from_scene/convert_object_to_json_dict/convert_lights_to_json_dict/json_dict_generator_from_lights.c \
					generator/json_generator_from_scene/convert_object_to_json_dict/convert_lights_to_json_dict/json_spot_generator.c \
					generator/json_generator_from_scene/convert_object_to_json_dict/convert_objects_to_json_dict/append_material_parameters_node.c \
					generator/json_generator_from_scene/convert_object_to_json_dict/convert_objects_to_json_dict/append_ppm_reader.c \
					generator/json_generator_from_scene/convert_object_to_json_dict/convert_objects_to_json_dict/convert_objects_to_json_dict.c \
					generator/json_generator_from_scene/convert_object_to_json_dict/convert_objects_to_json_dict/cylinder_generator.c \
					generator/json_generator_from_scene/convert_object_to_json_dict/convert_objects_to_json_dict/json_dict_generator_from_objects.c \
					generator/json_generator_from_scene/convert_object_to_json_dict/convert_objects_to_json_dict/plane_generator.c \
					generator/json_generator_from_scene/convert_object_to_json_dict/convert_objects_to_json_dict/quadric_generator.c \
					generator/json_generator_from_scene/convert_object_to_json_dict/convert_objects_to_json_dict/sphere_generator.c \
					generator/json_generator_from_scene/convert_object_to_json_dict/convert_objects_to_json_dict/triangle_generator.c \
					generator/json_generator_from_scene/convert_object_to_json_dict/json_dict_generator_from_camera.c \
					generator/json_generator_from_scene/convert_object_to_json_dict/utils/bool_to_json_value_node.c \
					generator/json_generator_from_scene/convert_object_to_json_dict/utils/color_to_json_list_node.c \
					generator/json_generator_from_scene/convert_object_to_json_dict/utils/double_to_json_value_node.c \
					generator/json_generator_from_scene/convert_object_to_json_dict/utils/ftoa_auto_adjust.c \
					generator/json_generator_from_scene/convert_object_to_json_dict/utils/round_to_digit.c \
					generator/json_generator_from_scene/convert_object_to_json_dict/utils/trunc_str.c \
					generator/json_generator_from_scene/convert_object_to_json_dict/utils/vec3_to_json_list_node.c \
					generator/json_generator_from_scene/json_generator_from_scene.c \
					generator/utils/put_indent.c \
					generator/utils/put_key_and_colon.c \
					generator/utils/put_value_separator.c \
					mlx/hook_helper/hook_fn/hook_fn_enter_cmd_mode.c \
					mlx/hook_helper/hook_fn/hook_fn_exit.c \
					mlx/hook_helper/hook_fn/hook_fn_handle_material.c \
					mlx/hook_helper/hook_fn/hook_fn_move_camera.c \
					mlx/hook_helper/hook_fn/hook_fn_rerendering.c \
					mlx/hook_helper/hook_fn/hook_fn_rotate_camera.c \
					mlx/hook_helper/hook_fn/hook_fn_save_scene.c \
					mlx/hook_helper/hook_fn/hook_fn_select_object.c \
					mlx/hook_helper/hook_fn/hook_fn_set_shift_off.c \
					mlx/hook_helper/hook_fn/hook_fn_set_shift_on.c \
					mlx/hook_helper/hook_fn/hook_fn_zoom_camera.c \
					mlx/hook_helper/mlx_hook_helper_init.c \
					mlx/hook_helper/mlx_hook_helper_init_button_press.c \
					mlx/hook_helper/mlx_hook_helper_init_key_press.c \
					mlx/hook_helper/mlx_hook_helper_init_key_release.c \
					mlx/hook_helper/mlx_hook_helper_set_hook.c \
					mlx/mlx_command_mode/command_line_parse/mlx_command_parser/mlx_del_parser.c \
					mlx/mlx_command_mode/command_line_parse/mlx_command_parser/mlx_dump_parser.c \
					mlx/mlx_command_mode/command_line_parse/mlx_command_parser/mlx_exit_parser.c \
					mlx/mlx_command_mode/command_line_parse/mlx_command_parser/mlx_help_parser.c \
					mlx/mlx_command_mode/command_line_parse/mlx_command_parser/mlx_mod_parser/cylinder_modify.c \
					mlx/mlx_command_mode/command_line_parse/mlx_command_parser/mlx_mod_parser/mlx_mod_parser.c \
					mlx/mlx_command_mode/command_line_parse/mlx_command_parser/mlx_mod_parser/plane_modify.c \
					mlx/mlx_command_mode/command_line_parse/mlx_command_parser/mlx_mod_parser/quadric_modify.c \
					mlx/mlx_command_mode/command_line_parse/mlx_command_parser/mlx_mod_parser/sphere_modify.c \
					mlx/mlx_command_mode/command_line_parse/mlx_command_parser/mlx_mod_parser/triangle_modify.c \
					mlx/mlx_command_mode/command_line_parse/mlx_command_parser/mlx_mod_parser/utils/modify_color.c \
					mlx/mlx_command_mode/command_line_parse/mlx_command_parser/mlx_mod_parser/utils/modify_double.c \
					mlx/mlx_command_mode/command_line_parse/mlx_command_parser/mlx_mod_parser/utils/modify_double_half.c \
					mlx/mlx_command_mode/command_line_parse/mlx_command_parser/mlx_mod_parser/utils/modify_vec3.c \
					mlx/mlx_command_mode/command_line_parse/mlx_command_parser/mlx_mod_parser/utils/modify_vec3_unit.c \
					mlx/mlx_command_mode/command_line_parse/mlx_command_parser/mlx_save_parser.c \
					mlx/mlx_command_mode/command_line_parse/mlx_file_dump.c \
					mlx/mlx_command_mode/command_line_parse/parse_mlx_command_line.c \
					mlx/mlx_command_mode/hook_fn_cmd_mode/hook_fn_delete.c \
					mlx/mlx_command_mode/hook_fn_cmd_mode/hook_fn_exit_cmd_mode.c \
					mlx/mlx_command_mode/hook_fn_cmd_mode/hook_fn_input_alphabet.c \
					mlx/mlx_command_mode/hook_fn_cmd_mode/hook_fn_input_digit.c \
					mlx/mlx_command_mode/hook_fn_cmd_mode/hook_fn_input_sp_char.c \
					mlx/mlx_command_mode/hook_fn_cmd_mode/hook_fn_return.c \
					mlx/mlx_command_mode/mlx_buffer/mlx_buffer_flush.c \
					mlx/mlx_command_mode/mlx_buffer/mlx_buffer_remove.c \
					mlx/mlx_command_mode/mlx_buffer/mlx_buffer_write.c \
					mlx/mlx_command_mode/mlx_hook_helper_init_key_press_cmd_mode.c \
					mlx/mlx_command_mode/utils/exit_cmd_mode.c \
					mlx/mlx_command_mode/utils/mlx_putcmd.c \
					mlx/mlx_command_mode/utils/reset_image.c \
					mlx/mlx_ptr_hook_button_press.c \
					mlx/mlx_ptr_hook_destroy_notify.c \
					mlx/mlx_ptr_hook_expose.c \
					mlx/mlx_ptr_hook_key_press.c \
					mlx/mlx_ptr_hook_key_release.c \
					mlx/mlx_ptr_hook_motion_notify.c \
					mlx/mlx_ptr_init.c \
					mlx/mlx_ptr_loop_hook_fn.c \
					mlx/mlx_ptr_main.c \
					mlx/mlx_ptr_set_hook.c \
					parse/json/check_duplicate_dict_key.c \
					parse/json/check_token/check_token.c \
					parse/json/check_token/statemachine/state_colon.c \
					parse/json/check_token/statemachine/state_comma.c \
					parse/json/check_token/statemachine/state_dict_end.c \
					parse/json/check_token/statemachine/state_dict_start.c \
					parse/json/check_token/statemachine/state_key.c \
					parse/json/check_token/statemachine/state_list_end.c \
					parse/json/check_token/statemachine/state_list_start.c \
					parse/json/check_token/statemachine/state_value.c \
					parse/json/check_token/statemachine_utils/check_state_end.c \
					parse/json/check_token/statemachine_utils/get_state.c \
					parse/json/check_token/statemachine_utils/is_state_closed.c \
					parse/json/check_token/statemachine_utils/is_value_token.c \
					parse/json/convert_json_to_json_object.c \
					parse/json/convert_json_to_token/convert_json_to_token.c \
					parse/json/convert_json_to_token/tokenize.c \
					parse/json/convert_token_to_json_object/convert_token_to_dict.c \
					parse/json/convert_token_to_json_object/convert_token_to_json_object.c \
					parse/json/convert_token_to_json_object/convert_token_to_list.c \
					parse/json/convert_token_to_json_object/prepare_json_object.c \
					parse/json/free_json_object.c \
					parse/json/sort_json_object.c \
					parse/rt/convert_rt_to_json.c \
					parse/rt/convert_rt_to_rt_objects_array/convert_rt_to_no_grouping_rt_objects.c \
					parse/rt/convert_rt_to_rt_objects_array/convert_rt_to_rt_objects_array.c \
					parse/rt/convert_rt_to_rt_objects_array/grouping_same_rt_objects.c \
					parse/rt/convert_rt_to_rt_objects_array/utils/check/check_duplicate_spot.c \
					parse/rt/convert_rt_to_rt_objects_array/utils/check/check_rt_object_format.c \
					parse/rt/convert_rt_to_rt_objects_array/utils/check/check_rt_object_option_format.c \
					parse/rt/convert_rt_to_rt_objects_array/utils/check/check_size_of_parameters.c \
					parse/rt/convert_rt_to_rt_objects_array/utils/free_no_grouping_rt_objects.c \
					parse/rt/convert_rt_to_rt_objects_array/utils/get_identifer/get_identifer_from_no_grouping_rt_objects.c \
					parse/rt/convert_rt_to_rt_objects_array/utils/get_identifer/get_identifer_from_rt_objects_array.c \
					parse/rt/convert_rt_to_rt_objects_array/utils/is_duplicate.c \
					parse/rt/convert_rt_to_rt_objects_array/utils/is_option_key.c \
					parse/rt/convert_rt_to_rt_objects_array/utils/sort/sort_no_grouping_rt_objects.c \
					parse/rt/convert_rt_to_rt_objects_array/utils/sort/sort_rt_object_options.c \
					parse/rt/free_rt_objects_array.c \
					parse/scene/append_object/add_parameters/add_additional_parameters/add_additional_parameters.c \
					parse/scene/append_object/add_parameters/add_additional_parameters/add_bump_map_parameter.c \
					parse/scene/append_object/add_parameters/add_additional_parameters/add_checkerboard_parameter.c \
					parse/scene/append_object/add_parameters/add_additional_parameters/add_material_parameter.c \
					parse/scene/append_object/add_parameters/add_additional_parameters/add_texture_map_paramter.c \
					parse/scene/append_object/add_parameters/add_light_color.c \
					parse/scene/append_object/add_parameters/add_object_color.c \
					parse/scene/append_object/append_lights/append_ambient.c \
					parse/scene/append_object/append_lights/append_light_to_vla.c \
					parse/scene/append_object/append_lights/append_lights.c \
					parse/scene/append_object/append_lights/append_spot.c \
					parse/scene/append_object/append_objects/append_cylinder.c \
					parse/scene/append_object/append_objects/append_object_to_vla.c \
					parse/scene/append_object/append_objects/append_objects.c \
					parse/scene/append_object/append_objects/append_plane.c \
					parse/scene/append_object/append_objects/append_quadric.c \
					parse/scene/append_object/append_objects/append_sphere.c \
					parse/scene/append_object/append_objects/append_triangle.c \
					parse/scene/camera_init.c \
					parse/scene/json_object_to_scene.c \
					parse/scene/utils/get_list.c \
					parse/scene/utils/is_between_min_to_max.c \
					parse/scene/utils/json_node_to_bool.c \
					parse/scene/utils/json_node_to_color.c \
					parse/scene/utils/json_node_to_double.c \
					parse/scene/utils/json_node_to_ppm_reader.c \
					parse/scene/utils/json_node_to_string.c \
					parse/scene/utils/json_node_to_vec3.c \
					parse/scene/utils/query_create.c \
					parse/scene/utils/query_set_boolean.c \
					parse/scene/utils/query_set_color.c \
					parse/scene/utils/query_set_double.c \
					parse/scene/utils/query_set_ppm_reader.c \
					parse/scene/utils/query_set_vec3.c \
					parse/scene/utils/select_json_node.c \
					parse/scene/utils/try_json_node_tof.c \
					parse/scene/utils/try_vec3_unit.c \
					parse/utils/add_double_quotes.c \
					parse/utils/check_extension.c \
					parse/utils/convert_extension.c \
					parse/utils/delete_commentout.c \
					parse/utils/get_next_removed_comment_line.c \
					parse/utils/is_list_with_value_nodes.c \
					parse/utils/is_only_value_node.c \
					parse/utils/is_with_double_quotes.c \
					parse/utils/json_node_free.c \
					parse/utils/json_node_new.c \
					parse/utils/remove_double_quotes.c \
					parse/utils/try_atof_limit.c \
					parse/utils/try_open_file.c \
					structs/ambient/ambient_free.c \
					structs/ambient/ambient_get_color.c \
					structs/ambient/ambient_get_id.c \
					structs/ambient/ambient_light_new.c \
					structs/ambient/ambient_new.c \
					structs/camera/camera_check_eye.c \
					structs/camera/camera_move.c \
					structs/camera/camera_rotate.c \
					structs/camera/camera_set_viewport.c \
					structs/camera/camera_zoom.c \
					structs/cartesian_system/cartesian_system_create.c \
					structs/cartesian_system/cartesian_system_map_from_standard.c \
					structs/cartesian_system/cartesian_system_map_to_standard.c \
					structs/cylinder/cylinder_free.c \
					structs/cylinder/cylinder_get_bump_normal.c \
					structs/cylinder/cylinder_get_checkerboard_color.c \
					structs/cylinder/cylinder_get_color.c \
					structs/cylinder/cylinder_get_dist.c \
					structs/cylinder/cylinder_get_id.c \
					structs/cylinder/cylinder_get_normal.c \
					structs/cylinder/cylinder_get_texture_color.c \
					structs/cylinder/cylinder_new.c \
					structs/cylinder/cylinder_object_new.c \
					structs/hit/hit_free.c \
					structs/hit/hit_get_color.c \
					structs/hit/hit_new.c \
					structs/image/image_init.c \
					structs/image/image_render_scene.c \
					structs/image/image_write_color.c \
					structs/light/light_free.c \
					structs/light/light_new.c \
					structs/material/material_create.c \
					structs/material/material_create_metal.c \
					structs/material/material_create_mirror.c \
					structs/material/material_create_plastic.c \
					structs/material_box/material_box_init.c \
					structs/material_box/material_box_swap.c \
					structs/object/object_free.c \
					structs/object/object_get_closest.c \
					structs/object/object_new.c \
					structs/plane/plane_free.c \
					structs/plane/plane_get_bump_normal.c \
					structs/plane/plane_get_checkerboard_color.c \
					structs/plane/plane_get_color.c \
					structs/plane/plane_get_dist.c \
					structs/plane/plane_get_id.c \
					structs/plane/plane_get_normal.c \
					structs/plane/plane_get_texture_color.c \
					structs/plane/plane_new.c \
					structs/plane/plane_object_new.c \
					structs/ppm_reader/ppm_reader_check_header.c \
					structs/ppm_reader/ppm_reader_free.c \
					structs/ppm_reader/ppm_reader_get_color.c \
					structs/ppm_reader/ppm_reader_get_next_line.c \
					structs/ppm_reader/ppm_reader_get_normal.c \
					structs/ppm_reader/ppm_reader_new.c \
					structs/quadric/quadric_dot.c \
					structs/quadric/quadric_free.c \
					structs/quadric/quadric_get_color.c \
					structs/quadric/quadric_get_dist.c \
					structs/quadric/quadric_get_id.c \
					structs/quadric/quadric_get_normal.c \
					structs/quadric/quadric_new.c \
					structs/quadric/quadric_object_new.c \
					structs/range/range_create.c \
					structs/ray/ray_at.c \
					structs/ray/ray_convert_to_color.c \
					structs/ray/ray_create.c \
					structs/ray/ray_from_to.c \
					structs/scene/scene_free.c \
					structs/scene/scene_init.c \
					structs/sphere/sphere_free.c \
					structs/sphere/sphere_get_bump_normal.c \
					structs/sphere/sphere_get_checkerboard_color.c \
					structs/sphere/sphere_get_color.c \
					structs/sphere/sphere_get_dist.c \
					structs/sphere/sphere_get_id.c \
					structs/sphere/sphere_get_normal.c \
					structs/sphere/sphere_get_texture_color.c \
					structs/sphere/sphere_new.c \
					structs/sphere/sphere_object_new.c \
					structs/spot/spot_free.c \
					structs/spot/spot_get_color.c \
					structs/spot/spot_get_id.c \
					structs/spot/spot_light_new.c \
					structs/spot/spot_new.c \
					structs/triangle/triangle_free.c \
					structs/triangle/triangle_get_color.c \
					structs/triangle/triangle_get_dist.c \
					structs/triangle/triangle_get_id.c \
					structs/triangle/triangle_get_normal.c \
					structs/triangle/triangle_new.c \
					structs/triangle/triangle_object_new.c \
					utils/check_triangle_vertex_valid.c \
					utils/convert_str_to_positive_int.c \
					utils/error_with_message_if.c \
					utils/get_viewport_ray.c \
					utils/is_higher.c \
					utils/is_lower.c \
					utils/is_normalized.c \
					utils/is_odd_2d.c \
					utils/is_zero.c \
					utils/map_3d_to_cylinder.c \
					utils/map_3d_to_spherical.c \
					utils/mod_double.c \
					utils/print_error.c \
					utils/print_warning.c \
					utils/rotate_two_vecs_clockwise.c \
					utils/solve_quadratic_equation.c


ifeq ($(MAKECMDGOALS), test_json)
	SRCS += $(TEST_MAIN_DIR)/main_json.c
else ifeq ($(MAKECMDGOALS), test_scene)
	SRCS += $(TEST_MAIN_DIR)/main_scene.c
else ifeq ($(MAKECMDGOALS), test_scene_to_json)
	SRCS += $(TEST_MAIN_DIR)/main_scene_to_json.c
else ifeq ($(MAKECMDGOALS), test_scene_to_json_bonus)
	SRCS += $(TEST_MAIN_DIR)/main_scene_to_json.c
else ifeq ($(MAKECMDGOALS), test_rt)
	SRCS += $(TEST_MAIN_DIR)/main_rt.c
else ifeq ($(MAKECMDGOALS), test_rt_bonus)
	SRCS += $(TEST_MAIN_DIR)/main_rt.c
else
	SRCS += main.c
endif

OBJS			=	$(patsubst %.o, $(OBJ_DIR)/%.o, $(SRCS:.c=.o))
OBJS			+=	$(LIB_OBJS)
DEPS			=	$(OBJS:.o=.d)
OBJ_SUBDIRS 	=	$(sort $(dir $(OBJS)))

OBJS_BONUS		=	$(patsubst %.o, $(OBJ_BONUS_DIR)/%.o, $(SRCS:.c=.o))
OBJS_BONUS		+=	$(LIB_OBJS_BONUS)
DEPS_BONUS		=	$(OBJS_BONUS:.o=.d)
OBJ_BONUS_SUBDIRS 	=	$(sort $(dir $(OBJS_BONUS)))

RM				=	rm -rf 


$(OBJ_SUBDIRS) : % :
	@mkdir -p $@
	
$(OBJ_BONUS_SUBDIRS) : % :
	@mkdir -p $@

$(LIB_OBJS) : $(OBJ_DIR)/%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDE) $(PRE_OPT) -o $@ -c $<

$(LIB_OBJS_BONUS) : $(OBJ_BONUS_DIR)/%.o : %.c
	$(CC) $(CFLAGS_BONUS) $(INCLUDE) $(PRE_OPT) -o $@ -c $<

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) $(PRE_OPT) -o $@ -c $<

$(OBJ_BONUS_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS_BONUS) $(INCLUDE) $(PRE_OPT) -o $@ -c $<

$(NAME) : $(MINILIBX_DIR) $(OBJ_SUBDIRS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) $(LINKER_OPT) -o$@

$(NAME_BONUS) : $(MINILIBX_DIR) $(OBJ_BONUS_SUBDIRS) $(OBJS_BONUS)
	$(CC) $(CFLAGS_BONUS) $(OBJS_BONUS) $(INCLUDE) $(LINKER_OPT) -o$@

$(MINILIBX_DIR) :
	git clone https://github.com/42Paris/minilibx-linux.git $(MINILIBX_DIR)
	make -C $(MINILIBX_DIR)

$(BONUS) : $(NAME_BONUS)

OK_OR_KO	=	"KO"
TEST_SH		=	"./test/test.sh"
JSON		=	"json"
SCENE		=	"scene"
SCENE_TO_JSON	= "scene_to_json"
SCENE_TO_JSON_BONUS	= "scene_to_json_bonus"
RT			=	"rt"
RT_BONUS	=	"rt_bonus"
# SRCS		+=	$(TEST_MAIN_DIR)/leaks.c

test_json : $(MINILIBX_DIR) $(OBJ_SUBDIRS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) $(LINKER_OPT) -ominiRT
	$(TEST_SH) $(OK_OR_KO) $(JSON)

test_scene : $(MINILIBX_DIR) $(OBJ_SUBDIRS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) $(LINKER_OPT) -ominiRT
	$(TEST_SH) $(OK_OR_KO) $(SCENE)

test_rt : $(MINILIBX_DIR) $(OBJ_SUBDIRS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) $(LINKER_OPT) -ominiRT
	$(TEST_SH) $(OK_OR_KO) $(RT)

test_rt_bonus : $(MINILIBX_DIR) $(OBJ_BONUS_SUBDIRS) $(OBJS_BONUS)
	$(CC) $(CFLAGS_BONUS) $(OBJS_BONUS) $(INCLUDE) $(LINKER_OPT) -ominiRT_bonus
	$(TEST_SH) $(OK_OR_KO) $(RT_BONUS)

test_scene_to_json : $(MINILIBX_DIR) $(OBJ_SUBDIRS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) $(LINKER_OPT) -ominiRT
	$(TEST_SH) $(OK_OR_KO) $(SCENE_TO_JSON)

test_scene_to_json_bonus : $(MINILIBX_DIR) $(OBJ_BONUS_SUBDIRS) $(OBJS_BONUS)
	$(CC) $(CFLAGS_BONUS) $(OBJS_BONUS) $(INCLUDE) $(LINKER_OPT) -ominiRT_bonus
	$(TEST_SH) $(OK_OR_KO) $(SCENE_TO_JSON_BONUS)

.PHONY	:	norm
norm :
	norminette $(SRC_DIR) $(INC_DIR) $(LIB_DIR)

.DEFAULT_GOAL	=	all
.PHONY	:	all
all		:	$(NAME)

.PHONY	:	clean
clean	:
	$(RM) $(OBJ_DIR)
	$(RM) $(OBJ_BONUS_DIR)

.PHONY	:	fclean 
fclean	:	clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

.PHONY	:	re
re		:	fclean all

-include $(DEPS) $(DEPS_BONUS)
