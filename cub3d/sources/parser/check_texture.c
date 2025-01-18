#include "../includes/cub.h"

static void set_wall_texture(t_data *data, char *line)
{
	if(ft_strncmp(line, "NO ", 3) == 0 && !data->texture->no_texture)
		data->texture->no_texture = ft_strdup(ft_strchr(line, ' ') + 1);
	if(ft_strncmp(line, "SO ", 3) == 0 && !data->texture->so_texture)
		data->texture->so_texture = ft_strdup(ft_strchr(line, ' ') + 1);
	if(ft_strncmp(line, "WE ", 3) == 0 && !data->texture->we_texture)
		data->texture->we_texture = ft_strdup(ft_strchr(line, ' ') + 1);
	if(ft_strncmp(line, "EA ", 3) == 0 && !data->texture->ea_texture)
		data->texture->ea_texture = ft_strdup(ft_strchr(line, ' ') + 1);
	if(ft_strncmp(line, "F ", 2) == 0 && !data->texture->f_texture)
		data->texture->f_texture = ft_strdup(ft_strchr(line, ' ') + 1);
	if(ft_strncmp(line, "C ", 2) == 0 && !data->texture->c_texture)
		data->texture->c_texture = ft_strdup(ft_strchr(line, ' ') + 1);
}

static int	check_rgb(t_data *data)
{
	char	**f_split;
	char	**c_split;
	int		i;

	i = 0;
	f_split = ft_split(data->texture->f_texture, ',');
	c_split = ft_split(data->texture->c_texture, ',');
	while (f_split[i] && c_split[i])
	{
		if (ft_atoi(f_split[i]) > 255
			|| ft_atoi(c_split[i]) > 255)
			{
				return (-1);
			}
		i++;
	}
	free_array(f_split);
	free_array(c_split);
	if (i != 3)
		return (-1);
	return (0);
}

static int	verify_texture(t_data *data)
{
	if (!data->texture->so_texture
		|| !data->texture->no_texture
		|| !data->texture->no_texture
		|| !data->texture->no_texture
		|| check_rgb(data) == -1)
		return (-1);
	return (0);
}

int	check_walls_texture(t_data *data, char *file)
{
	char	*line;
	int		fd;
	int		i;

	i = 1;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line && i < 8)
	{
		if (i != 5) //Para não considerar a linha vazia
			set_wall_texture(data, line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	if (verify_texture(data) == -1)
		return (-1);
	return (0);
}