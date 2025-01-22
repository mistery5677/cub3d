#include "../includes/cub.h"

int main(int argc, char **argv)
{
	t_data	*data;

    (void)argc;
    (void)argv;
	data = malloc(sizeof(t_data));
	if (!data)
	{
		ft_putstr_fd("Error allocating memory\n", 2);
		exit(127);
	}
	initialize_data(data);
	if (check_map(data, argc, argv) == -1)
	{
		free_all(data);
		return (-1);
	}
	create_window(data);
	debug_window(data);
	//ray_cast(data);
	gameplay(data);
	mlx_loop(data->mlx);
}
