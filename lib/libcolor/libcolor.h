#ifndef LIBCOLOR_H
# define LIBCOLOR_H

typedef struct s_color
{
	double	red;
	double	green;
	double	blue;
}	t_color;

t_color			color_create(double red, double green ,double blue);
unsigned int	color_cast(t_color color);

#endif
