#include "../../includes/cub.h"

// IMPROVED mlx_put_pixel
void put_pixel(int x, int y, int color, t_image *image)
{
    int index;

    if (!image || !image->addr)
        return;
    if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0 )
        return ;
    index = y * image->line_length + x * image->bits_per_pixel / 8;
    image->addr[index] = color & 0xFF;
    image->addr[index + 1] = (color >> 8) & 0xFF;
    image->addr[index + 2] = (color >> 16) & 0xFF;

}

void draw_square(int x, int y, int size, int color, t_image *image)
{
    int i, j;

    i = 0;
    while (i < size)
    {
        j = 0;
        while (j < size)
        {
            put_pixel(x + i, y + j, color, image);
            j++;
        }
        i++;
    }
}

void clear_image(t_image *image)
{
    int i;
    int x;


    i = 0;
    while (i < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            put_pixel(x, i, 0.000000, image);
            x++;
        }
        i++;
    }
}

void draw_map(t_data *data)
{
    int y;
    int x;

    x = 0;
    while (data->map->matrix[x])
    {
        y = 0;
        while (data->map->matrix[x][y])
        {
            if (data->map->matrix[x][y] == WALL)
                draw_square(y * 40, x * 40, 40, 0x00FF00, data->image);
            if (data->map->matrix[x][y] == 'N')
                draw_square(data->player->y_pst * 40, data->player->x_pst * 40, 20, 0xFF0000, data->image);
            y++;
        }
        x++;
    }
}

void init_debug(t_image *image)
{
    image->mlx = mlx_init();
    image->win = mlx_new_window(image->mlx, WIDTH, HEIGHT, "Debug");
    image->img = mlx_new_image(image->mlx, WIDTH, HEIGHT);
    image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel, &image->line_length, &image->endian);
}

int move_player(int key_pressed, t_data *data)
{
    float angle_speed;
    float cos_angle;
    float sin_angle;

    cos_angle = cos(data->player->angle);
    sin_angle = sin(data->player->angle);
    angle_speed = 0.1;
    (void)cos_angle;
    (void)sin_angle;
    printf("Key_pressed %d\n", key_pressed);
    if (key_pressed == LEFT)
    {
        data->player->angle -= angle_speed;
    }
    if (key_pressed == RIGHT)
    {
        data->player->angle += angle_speed;
    }
    if (data->player->angle > 2 * PI)
    {
        data->player->angle = 0;
    }
    if (data->player->angle < 0)
    {
        data->player->angle = 2 * PI;
    }
    if (key_pressed == W)
    {
        data->player->x_pst -= 0.1;
    }
    if (key_pressed == S)
    {
        data->player->x_pst += 0.1;
    }
    if (key_pressed == A)
    {
        data->player->y_pst -= 0.1;
    }
    if (key_pressed == D)
    {
        data->player->y_pst += 0.1;
    }
    printf("data y %f\n", data->player->y_pst);
    clear_image(data->image);
    draw_map(data);
    mlx_put_image_to_window(data->image->mlx, data->image->win, data->image->img, 0, 0);
    return (0);
}


void debug_window(t_data *data)
{
    t_image *image;

    image = malloc(sizeof(t_image));
    data->image = image;
    init_debug(image);
    draw_map(data);
    mlx_put_image_to_window(image->mlx, image->win, image->img, 0, 0);
    mlx_hook(data->image->win, KeyPress, KeyPressMask, move_player, data);
    mlx_loop(image->mlx);
}