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

void draw_square (int x, int y, int size, int color, t_data *data)
{
    for (int i = 0; i < size; i++)
        put_pixel(x + i, y, color, data->image);
    for (int i = 0; i < size; i++)
        put_pixel(x, y + i, color, data->image);
    for (int i = 0; i < size; i++)
        put_pixel(x + size, y + i, color, data->image);
    for (int i = 0; i < size; i++)
        put_pixel(x + i, y + size, color, data->image);    
}

void draw_map(t_data *data)
{
    int color;
    int y;
    int x;

    y = 0;
    color = 0x00FF00;
    while (data->map->matrix[y])
    {
        x = 0;
        while (data->map->matrix[y][x])
        {
            if (data->map->matrix[y][x] == '1')
                draw_square(x *64, y *64, 64, color, data);
            x++;
        }
        y++;
    }
}

void init_debug(t_image *image)
{
    image->mlx = mlx_init();
    image->win = mlx_new_window(image->mlx, WIDTH, HEIGHT, "Debug");
    image->img = mlx_new_image(image->mlx, WIDTH, HEIGHT);
    image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel, &image->line_length, &image->endian);
    mlx_put_image_to_window(image->mlx, image->win, image->img, 0, 0);
}

int key_press(int key_pressed, t_data *data)
{
    //printf("key_pressed %d\n", key_pressed);
    if (key_pressed == W)
        data->player->key_up = true;
    if (key_pressed == S)
        data->player->key_down = true;
    if (key_pressed == D)
        data->player->key_right = true;
    if (key_pressed == A)
        data->player->key_left = true;
    if (key_pressed == LEFT)
        data->player->left_rotate = true;
    if (key_pressed == RIGHT)
        data->player->right_rotate = true;
    return (0);
}

int key_release(int key_pressed, t_data *data)
{
    if (key_pressed == W)
        data->player->key_up = false;
    if (key_pressed == S)
        data->player->key_down = false;
    if (key_pressed == D)
        data->player->key_right = false;
    if (key_pressed == A)
        data->player->key_left = false;
    if (key_pressed == LEFT)
        data->player->left_rotate = false;
    if (key_pressed == RIGHT)
        data->player->right_rotate = false;
    return (0);
}

void move_player(t_data *data)
{
    float speed;
    float angle_speed; 
    float cos_angle;
    float sin_angle;

    speed = 1;
    angle_speed = 0.02;
    cos_angle = cos(data->player->angle);
    sin_angle = sin(data->player->angle);

    if (data->player->left_rotate)
        data->player->angle -= angle_speed;
    if (data->player->right_rotate)
        data->player->angle += angle_speed;
    if (data->player->angle > 2 * PI)
        data->player->angle = 0;
    if (data->player->angle < 0)
        data->player->angle = 2 * PI;

    if (data->player->key_up)
    {
        data->player->x_pst += cos_angle *speed;
        data->player->y_pst += sin_angle *speed;
    }
    if (data->player->key_down)
    {
        data->player->x_pst -= cos_angle *speed;
        data->player->y_pst -= sin_angle *speed;
    }
    if (data->player->key_left)
    {
        data->player->x_pst += cos_angle *speed;
        data->player->y_pst -= sin_angle *speed;
    }
    if (data->player->key_right)
    {
        data->player->x_pst -= cos_angle *speed;
        data->player->y_pst += sin_angle *speed;
    }
}

bool touch(float px, float py, t_data *data)
{
    int x;
    int y;

    y = py / BLOCK;
    x = px / BLOCK;
    if (data->map->matrix[y][x] == '1')
        return true;
    return false;
}

int draw_loop(t_data *data)
{
    float ray_x;
    float ray_y;
    float cos_angle;
    float sin_angle;

    ray_x = data->player->x_pst;
    ray_y = data->player->y_pst;
    cos_angle = cos(data->player->angle);
    sin_angle = sin(data->player->angle);
    move_player(data);
    clear_image(data->image);
    draw_map(data);
    draw_square(data->player->x_pst, data->player->y_pst, 5, 0x00FF00, data);

    while (!touch(ray_x, ray_y, data))
    {
        put_pixel(ray_x, ray_y, 0xFF0000, data->image);
        ray_x += cos_angle;
        ray_y += sin_angle;
    }
    mlx_put_image_to_window(data->image->mlx, data->image->win, data->image->img, 0, 0);
    return (0);
}

void debug_window(t_data *data)
{
    t_image *image;

    image = malloc(sizeof(t_image));

    data->player->key_up = false;
    data->player->key_down = false;
    data->player->key_left = false;
    data->player->key_right = false;
    
    data->player->x_pst = WIDTH / 2;
    data->player->y_pst = HEIGHT / 2;
    data->player->angle = PI / 2;
    data->player->left_rotate = false;
    data->player->right_rotate = false;
    data->image = image;
    init_debug(image);
    mlx_hook(image->win, KeyPress, KeyPressMask, key_press, data);
    mlx_hook(image->win, KeyRelease, KeyReleaseMask, key_release, data);
    mlx_loop_hook(image->mlx, draw_loop, data);
    mlx_loop(image->mlx);
}