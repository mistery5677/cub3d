#include "cub.h"

int	main(int argc, char **argv)
{
	static t_data data;

	initialize_data(&data);
	if (!is_map_valid(&data, argc, argv))
		return (close_game(&data), EXIT_FAILURE);
	print_matrix(data.map->matrix);
	if (DEBUG == 1)
	{
		create_window(&data);
		gameplay(&data);
		debug_window(&data);
	}
	else
	{
		create_window(&data);
		gameplay(&data);
		mlx_loop(data.mlx);
	return(0);
	}
}
