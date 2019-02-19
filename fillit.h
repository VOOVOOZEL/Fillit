#ifndef FILLIT_H

# define FILLIT_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct	s_figure
{
	int			*x;
	int			*y;
	char		c;
}				t_figure;

char			**g_map;

int				ft_count_figures(char *str_figures);
void			ft_free_map(char **arr);
char			*ft_strncpy(char *dst, char *src, int len);
char			*ft_strnew(int size);
int				ft_check_all_same(t_figure cur_fig, t_figure next_fig);
void			ft_render_map(int cell);
int				ft_find_solution(t_figure *crd, int figures, int cells);;
char			*ft_get_map(int argc, char **argv);
void			ft_bzero(void *s, size_t n);
int				ft_get_str_len(char *argv);
int				ft_strlen(const char *s);
char			*ft_specstrnew(int size);
int				ft_print_error(int signal);
int				ft_sqrt(int nb);
int				ft_solving(t_figure *coordinates, int figures,
					int cells, char **new_map);
void			ft_print_map(char **map, int cells);;
t_figure		*ft_record_all_figures(char *str_figures, int figures);
char			**ft_create_map(int cell);
int				ft_check_symbols(char *map);


#endif
