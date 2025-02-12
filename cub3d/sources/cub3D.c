#include "cub.h"

int	main(int argc, char **argv)
{
	t_data	*data;

    (void)argc;
    (void)argv;
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		exit(print_error(NULL, strerror(errno), ENOMEM)); // ! using ENOMEM 12
	initialize_data(data);
	if (!is_map_valid(data, argc, argv))
		return (close_game(data), EXIT_FAILURE);
	// printf("CHECK\n");
	// close_game(data); // ! testing if parsing frees successfully
	data->player->x_pst = 1;
	data->player->y_pst = 1;
	if (DEBUG == 1)
	{
		create_window(data);
		gameplay(data);
		debug_window(data);
	}
	else
	{
		create_window(data);
		gameplay(data);
		mlx_loop(data->mlx);
	return(0);
	}
}
