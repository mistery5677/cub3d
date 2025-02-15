#include "cub.h"

// static void	draw_walls(t_data *dt, t_texture *tx, int i, int tex_x)
// {
// 	float	step;
// 	float	tex_pos;
// 	int		tex_y;
// 	int 	y;

// 	step = (float)BLOCK / dt->wall->height;
// 	if (dt->wall->start_y < 0)
// 		tex_pos = -dt->wall->start_y * step;
// 	else
// 		tex_pos = 0;

//     dt->wall->texture = dt->texture->no_texture;
// 	tx->img = mlx_get_data_addr(dt->wall->texture,
// 			&(tx)->bpp, &(tx)->size_line, &(tx)->endian);

// 	if (dt->wall->start_y < 0)
// 		y = 0;
// 	else
// 		y = dt->wall->start_y;
// 	while (y < dt->wall->end_y && y < HEIGHT)
// 	{
// 		tex_y = ((int)tex_pos) % BLOCK;
// 		tx->color = get_pixel_color(dt, tx->img, tex_x, tex_y);
// 		put_pixel(i, y, tx->color, dt);
// 		tex_pos += step;
// 		y++;
// 	}
// }

// Calculate the Euclidean distance between two points
float calculate_distance(float x1, float y1, float x2, float y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

// Fix the fish-eye effect by adjusting the distance
float fix_fisheye(float raw_distance, float ray_angle, float player_angle) {
    float angle_diff = ray_angle - player_angle;
    return raw_distance * cos(angle_diff);
}

// Cast a ray and calculate the distance to the wall
void cast_ray(t_data *data, float ray_angle) {
    // Initialize ray direction
    data->ray->ray_dir_x = cos(ray_angle);
    data->ray->ray_dir_y = sin(ray_angle);

    // Perform DDA algorithm to find the wall intersection
    // (This part is simplified for clarity; replace with your DDA implementation)
    float wall_x;
    float wall_y;

    wall_x = (int)data->player->x_pst;
	wall_y = (int)data->player->y_pst;
	init_ray(data->ray, data->player->angle - PI / 6);
	init_dir_dist(data->ray, data->player, wall_x, wall_y);
	while (data->map->matrix[(int)wall_y / BLOCK][(int)wall_x / BLOCK] != '1')
	{
		if (data->ray->side_dist_x < data->ray->side_dist_y)
		{
			data->ray->side_dist_x += data->ray->delta_x;
			wall_x += data->ray->step_x;
			data->wall->side = VERTICAL;
		}
		else
		{
			data->ray->side_dist_y += data->ray->delta_y;
			wall_y += data->ray->step_y;
			data->wall->side = HORIZONTAL;
		}
	}
    // Calculate raw distance
    float raw_distance = calculate_distance(data->player->x_pst, data->player->y_pst, wall_x, wall_y);
    (void)raw_distance;
    // Fix fish-eye effect
    data->ray->distance = fix_fisheye(raw_distance, ray_angle, data->player->angle);
}

void draw_wall_slice(t_data *data, int x, float wall_height) {
    // Draw a vertical slice of the wall
    int start_y = (HEIGHT - wall_height) / 2;
    int end_y = start_y + wall_height;

    for (int y = start_y; y < end_y; y++) {
        // Calculate texture coordinates and draw the pixel
        // (Replace with your texture mapping logic)
        int color = 0xFF0000; // Example: red color
        put_pixel(x, y, color, data);
    }
}

void render_scene(t_data *data) {
    float ray_angle_start = data->player->angle - FOV / 2;
    float ray_angle_end = data->player->angle + FOV / 2;
    float ray_angle_step = FOV / WIDTH;

    (void)ray_angle_end;
    for (int x = 0; x < WIDTH; x++) {
        float ray_angle = ray_angle_start + x * ray_angle_step;
        
        // Cast the ray and calculate the distance
        cast_ray(data, ray_angle);
        
        // Calculate wall height
        float wall_height = (BLOCK / data->ray->distance) * (WIDTH / 2);
        
        // Draw the wall slice
        draw_wall_slice(data, x, wall_height);
        // draw_walls(data, data->texture, x, wall_height);
    }
    //(void)draw_walls;
}