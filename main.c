/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrown-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 15:57:58 by lbrown-b          #+#    #+#             */
/*   Updated: 2019/01/31 19:35:54 by hrickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_free_map(char **map)
{
	char **st;

	if (!map)
		return ;
	st = map;
	while (*st)
		free(*(st++));
	free(map);
}

void		ft_render_map(int cell)
{
	int			row;

	g_map = (char**)malloc(sizeof(char*) * (cell + 1));
	if (!g_map)
		ft_print_error(2);
	else
	{
		row = -1;
		while (++row < cell)
		{
			g_map[row] = ft_strnew(cell);
			if (g_map[row] == NULL)
				ft_free_map(g_map);
		}
		g_map[row] = NULL;
	}
}

void	ft_find_res(char *str_figures)
{
	int			figures;
	t_figure	*arr_figs;
	int			cells;

	figures = ft_count_figures(str_figures);
	arr_figs = ft_record_all_figures(str_figures, figures);
	cells = ft_sqrt(figures * 4);
	ft_render_map(cells);
	if (ft_find_solution(arr_figs, figures, cells))
		ft_print_map(g_map, cells);
	else
	{
		free(g_map);
		ft_render_map(++cells);
		while (!(ft_find_solution(arr_figs, figures, cells)))
			ft_render_map(++cells);
		ft_print_map(g_map, cells);
	}
}

int		main(int argc, char **argv)
{
	char		*map;
	
	if (!(map = ft_get_map(argc, argv)))
		return (0);
	ft_find_res(map);
}