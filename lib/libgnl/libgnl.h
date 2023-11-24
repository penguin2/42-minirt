/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgnl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 07:48:42 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/24 17:32:23 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGNL_H
# define LIBGNL_H

# define READER_BUFFER_SIZE 1000

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stddef.h>

// 'capacity' range : [1, SIZE_MAX - 1]
// 'size' range : [0, capacity]
typedef struct s_string{
	char		*content;
	size_t		capacity;
	size_t		size;
}				t_string;

typedef struct s_reader{
	int		fd;
	char	*buf;
	size_t	size;
	size_t	cur;
}			t_reader;

typedef enum e_gnl_mode{
	GNL_MODE_NEWLINE,
	GNL_MODE_ALL,
	GNL_MODE_RESET
}	t_gnl_mode;

char		*get_next_line(int fd, t_gnl_mode mode);

// reader_utils
int			reader_init(t_reader **preader, int fd);
void		reader_free(t_reader **preader);
ssize_t		reader_fill_buffer(t_reader *reader);

// reader_read
typedef int	(*t_fn_set_string)(t_reader*, t_string*);
char		*reader_read(t_reader **preader, t_fn_set_string set_string);
// set_string
int			set_one_line(t_reader *reader, t_string *string);
int			set_all(t_reader *reader, t_string *string);

// string_utils
ssize_t		string_init(t_string **pstr, size_t size);
void		string_free(t_string **pstr);
char		*string_to_cstring(const t_string *str);
void		*string_memcpy(void *dst, const void *src, size_t n);

// string_push_back
int			string_push_back(t_string *str, char c);
int			string_push_back_str(t_string *dst, const char *src, size_t size);

#endif
