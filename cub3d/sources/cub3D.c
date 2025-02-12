#include "cub.h"

int	main(int argc, char **argv)
{
	static t_data data;

	initialize_data(&data);
	if (!is_map_valid(&data, argc, argv))
		return (close_game(&data), EXIT_FAILURE);
	print_matrix(data.map->matrix);
	printf("north path %s\n", data.texture->no_path);
	printf("east path %s\n", data.texture->ea_path);
	printf("south path %s\n", data.texture->so_path);
	printf("west path %s\n", data.texture->we_path);
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
