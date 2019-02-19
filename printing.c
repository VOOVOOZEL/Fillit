#include "fillit.h"

static void	ft_putendl(char const *s)
{
	int i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void		ft_print_map(char **map, int cells)
{
	int i;

	i = 0;
	while (i < cells)
	{
		ft_putendl(map[i]);
		i++;
	}
}

int			ft_check_symbols(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == '.' || map[i] == '#' || map[i] == '\n' || map[i] == '\0')
			i++;
		else
			return (0);
	}
	return (1);
}

int			ft_get_str_len(char *argv)
{
	int		str_len;
	int		fd;
	char	*buff;

	str_len = 0;
	if ((fd = open(argv, O_RDONLY)) == -1)
		return (ft_print_error(0));
	str_len = 0;
	while ((read(fd, &buff, 1) > 0) && str_len < 546)
		++str_len;
	close(fd);
	return (str_len);
}

void		ft_bzero(void *s, size_t n)
{
	char	*str;

	str = (char*)s;
	while (n--)
		*(str++) = '\0';
}