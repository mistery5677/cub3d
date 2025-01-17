#include "../includes/cub.h"

static int	check_name(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (str[i + 1] == 'c'
				&& str[i + 2] == 'u'
				&& str[i + 3] == 'b'
				&& str[i + 4] == '\0')
				return (0);
			else
				return (-1);
		}
		i++;
	}
	return (-1);
}

int	check_map(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
	{
		ft_putstr_fd("Error: Wrong number of arguments\n", 2);
		return (-1);
	}
	if (check_name(argv[1]) == -1)
	{
		ft_putstr_fd("Error: Wrong file extension\n", 2);
		return (-1);
	}
	return (0);
}
