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
		close_game(data);
		return (-1);
	}
	if (DEBUG == 1)
	{
		create_window(data);
		gameplay(data);
		//draw_loop(data);
		debug_window(data);
		//mlx_loop(data->mlx);
	}
	else
	{
		create_window(data);
		gameplay(data);
		mlx_loop(data->mlx);
	}
}
