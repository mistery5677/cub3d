#include "../includes/cub.h"

void	initialize_data(t_data *data)
{
	data->texture = malloc(sizeof(t_texture));
	if (!data->texture)
	{
		ft_putstr_fd("Error allocating memory\n", 2);
		exit(127);
	}
	data->texture->no_texture = NULL;
    data->texture->so_texture = NULL;
    data->texture->we_texture = NULL;
    data->texture->ea_texture = NULL;
    data->texture->f_texture = NULL;
    data->texture->c_texture = NULL;
}

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
		return (-1);
	printf("Value %s", data->texture->no_texture);
	printf("Value %s", data->texture->so_texture);
	printf("Value %s", data->texture->we_texture);
	printf("Value %s", data->texture->ea_texture);
	printf("Value %s", data->texture->f_texture);
	printf("Value %s", data->texture->c_texture);
}
