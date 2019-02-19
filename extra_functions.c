#include "fillit.h"

int		ft_sqrt(int nb)
{
	int		i;

	i = 2;
	while (i * i < nb)
		i++;
	return (i);
}

int		ft_strlen(const char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strncpy(char *dst, char *src, int len)
{
	char	*ptr;

	ptr = dst;
	while (len)
	{
		if (!*src)
			break ;
		else
			*ptr++ = *src++;
		len--;
	}
	while (len)
	{
		*ptr++ = '\0';
		len--;
	}
	return (dst);
}

char	*ft_strnew(int size)
{
	char	*str;
	int		i;

	i = 0;
	str = (char*)malloc(sizeof(char) * (size + 1));
	if (str)
	{
		while (i < size)
		{
			str[i] = '.';
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	else
		return (NULL);
}

int		ft_check_all_same(t_figure cur_fig, t_figure next_fig)
{
	int		i;

	i = 0;
	while (i != 4)
	{
		if (cur_fig.x[i] == next_fig.x[i]
			&& cur_fig.y[i] == next_fig.y[i])
			i++;
		else
			return (0);
	}
	return (1);
}
