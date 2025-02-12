#include "cub.h"

int	main(int argc, char **argv)
{
	// t_data	*data;
	static t_data data;

	// data = ft_calloc(1, sizeof(t_data));
	// if (!data)
		// exit(print_error(NULL, strerror(errno), ENOMEM)); // ! using ENOMEM 12
	initialize_data(&data);
	if (!is_map_valid(&data, argc, argv))
		return (close_game(&data), EXIT_FAILURE);
	print_matrix(data.map->matrix);
	data.active = 1;
	// close_game(&data); // ! testing if parsing frees successfully
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
