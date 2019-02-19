#include "fillit.h"

void	ft_del_figure(t_figure crd, int x, int y)
{
	int x2;
	int i;
	int y2;

	i = 0;
	x2 = x;
	y2 = y;
	while (i != 4)
	{
		x = x2 + crd.x[i];
		y = y2 + crd.y[i];
		g_map[y][x] = '.';
		i++;
	}
}

int		ft_is_putin(t_figure crd, int x, int y, int cells)
{
	int i;
	int x2;
	int y2;

	i = 0;
	x2 = x;
	y2 = y;
	while (i != 4)
	{
		x = x2 + crd.x[i];
		y = y2 + crd.y[i];
		if (x > cells || y > cells)
			return (0);
		if (g_map[y][x] == '.')
			i++;
		else
			return (0);
	}
	return (1);
}

void	put_figure_on_map(t_figure crd, int x, int y, char **g_map)
{
	int i;
	int y2;
	int x2;

	i = 0;
	x2 = x;
	y2 = y;
	while (i != 4)
	{
		x = x2 + crd.x[i];
		y = y2 + crd.y[i];
		g_map[y][x] = crd.c;
		i++;
	}
}

#include <stdio.h>

int		ft_find_solution(t_figure *crd, int figures, int cells)
{
	int	x;
	int	y;

	x = -1;
	y = 0;
	while (y != cells && ++x != -2)
	{
		if (ft_is_putin(*crd, x, y, cells - 1) == 1)
		{
			put_figure_on_map(*crd, x, y, g_map);
			if (figures - 1 != 0)
			{
				if (ft_find_solution(++crd, figures - 1, cells))
					return (1);
				if (!(ft_check_all_same(*crd, *(crd - 1))))
					ft_del_figure(*--crd, x, y);
			}
			else
				return (1);
		}
		(x == cells) ? (y = y + 1) : y;
		(x == cells) ? (x = -1) : x;
	}
	return (0);
}
