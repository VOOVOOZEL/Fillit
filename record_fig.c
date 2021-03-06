#include "fillit.h"

int			ft_count_figures(char *str_figures)
{
	int			hash;
	int			count;

	hash = 0;
	while (*str_figures)
	{
		if (*str_figures == '#')
			hash++;
		str_figures++;
	}
	count = hash / 4;
	return (count);
}

static int	*ft_putin_x(char *str_figures)
{
	int			*arr;
	int			i;
	int			j;
	int			x;

	i = -1;
	j = -1;
	x = 0;
	if (!(arr = (int*)malloc(sizeof(int) * 4)))
		return (NULL);
	while (++i < 21)
	{
		(str_figures[i] == '#') ? arr[++j] = x : j;
		(str_figures[i] == '\n') ? x = -1 : x;
		x++;
	}
	while (arr[0] != 0 && arr[1] != 0 && arr[2] != 0 && arr[3] != 0 && (j = -1))
	{
		while (++j != 4)
			arr[j] = arr[j] - 1;
	}
	return (arr);
}

static int	*ft_putin_y(char *str_figures)
{
	int			*arr;
	int			i;
	int			j;
	int			y;

	i = 0;
	j = 0;
	y = 0;
	if (!(arr = (int*)malloc(sizeof(int) * 4)))
		return (NULL);
	while (i < 21)
	{
		(str_figures[i] == '#') ? arr[j] = y : j;
		(str_figures[i] == '#') ? j++ : j;
		(str_figures[i] == '\n') ? y++ : y;
		i++;
	}
	while (arr[0] != 0 && arr[1] != 0 && arr[2] != 0 && arr[3] != 0 && (j = -1))
		while (++j != 4)
			arr[j] = arr[j] - 1;
	return (arr);
}

t_figure	*ft_record_all_figures(char *str_figures, int figures)
{
	t_figure	*arr_figures;
	int			i;
	int			j;
	int			str_len;
	char		c;

	str_len = ft_strlen(str_figures);
	arr_figures = (t_figure*)malloc(sizeof(t_figure) * figures);
	if (!arr_figures)
		return (NULL);
	i = 0;
	j = 0;
	c = 'A';
	while (j < str_len)
	{
		arr_figures[i].x = ft_putin_x(&str_figures[j]);
		arr_figures[i].y = ft_putin_y(&str_figures[j]);
		arr_figures[i].c = c++;
		j = j + 21;
		i++;
	}
	return (arr_figures);
}
