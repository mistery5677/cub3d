#include "../../includes/cub.h"

// // IMPROVED mlx_debug_put_pixel
void debug_put_pixel(int x, int y, int color, t_image_debug *image)
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

void debug_clear_image(t_image_debug *image)
{
    int i;
    int x;


    i = 0;
    while (i < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            debug_put_pixel(x, i, 0.000000, image);
            x++;
        }
        i++;
    }
}

void debug_draw_square (int x, int y, int size, int color, t_data *data)
{
    for (int i = 0; i < size; i++)
        debug_put_pixel(x + i, y, color, data->debug);
    for (int i = 0; i < size; i++)
        debug_put_pixel(x, y + i, color, data->debug);
    for (int i = 0; i < size; i++)
        debug_put_pixel(x + size, y + i, color, data->debug);
    for (int i = 0; i < size; i++)
        debug_put_pixel(x + i, y + size, color, data->debug);    
}

void debug_draw_map(t_data *data)
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
                debug_draw_square(x *64, y *64, 64, color, data);
            x++;
        }
        y++;
    }
}

void debug_init_debug(t_image_debug *image)
{
    image->mlx = mlx_init();
    image->win = mlx_new_window(image->mlx, WIDTH, HEIGHT, "Debug");
    image->img = mlx_new_image(image->mlx, WIDTH, HEIGHT);
    image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel, &image->line_length, &image->endian);
    mlx_put_image_to_window(image->mlx, image->win, image->img, 0, 0);
}

int debug_key_press(int key_pressed, t_data *data)
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

int debug_key_release(int key_pressed, t_data *data)
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

void debug_move_player(t_data *data)
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
        data->player->angle -= 2 * PI;
    if (data->player->angle < 0)
        data->player->angle += 2 * PI;

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
        data->player->x_pst += sin_angle * speed;
        data->player->y_pst -= cos_angle * speed;
    }
    if (data->player->key_right)
    {
        data->player->x_pst -= sin_angle * speed;
        data->player->y_pst += cos_angle * speed;
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

float debug_calculate_distance(float x, float y) // This fucntion has the fish eye
{
    return sqrt(x * x + y * y);
}

float debug_fixed_calculate_distance(float x1, float y1, float x2, float y2, t_data *data)
{
    float delta_x;
    float delta_y;
    float angle;
    float fix_distance;

    delta_x = x2 - x1;
    delta_y = y2 - y1;
    angle = atan2(delta_y, delta_x) - data->player->angle;
    fix_distance = debug_calculate_distance(delta_x, delta_y) * cos(angle);
    return fix_distance;
}

void debug_draw_ray(t_data *data, float start_x, int i)
{
    float cos_angle;
    float sin_angle;
    float ray_x;
    float ray_y;

    (void)i;
    ray_x = data->player->x_pst;
    ray_y = data->player->y_pst;
    sin_angle = sin(start_x);
    cos_angle = cos(start_x);
    while (!touch(ray_x, ray_y, data))
    {
        if (DEBUG)
        {
            debug_put_pixel(ray_x, ray_y, 0xFF0000, data->debug); // Draws the ray
        }
        ray_x += cos_angle;
        ray_y += sin_angle; 
    }
    if (!DEBUG) // Draw walls
    {
        float distance;
        float wall_height;
        int start_y;
        int end;

        // distance = calculate_distance(ray_x - data->player->x_pst, ray_y - data->player->y_pst); //Shows in a fish eye perspective 
        distance = debug_fixed_calculate_distance(data->player->x_pst, data->player->y_pst, ray_x, ray_y, data);
        wall_height = (BLOCK / distance) * (WIDTH / 2);
        start_y = (HEIGHT - wall_height) / 2;
        end = start_y + wall_height;
        while (start_y < end)
        {
            debug_put_pixel(i, start_y, 0x00FF00, data->debug);
            start_y++;
        }
    //Calculate distance
    }
}

int debug_draw_loop(t_data *data)
{
    // float ray_x;
    // float ray_y;
    // float cos_angle;
    // float sin_angle;

    // ray_x = data->player->x_pst;
    // ray_y = data->player->y_pst;
    // cos_angle = cos(data->player->angle);
    // sin_angle = sin(data->player->angle);
    debug_move_player(data);
    debug_clear_image(data->debug);
    if (DEBUG)
    {
        debug_draw_square(data->player->x_pst, data->player->y_pst, 5, 0x00FF00, data);
        debug_draw_map(data);
        mlx_put_image_to_window(data->debug->mlx, data->debug->win, data->debug->img, 0, 0);
    }


    float fraction;
    float start_x;
    int i;

    i = 0;
    fraction = PI / 3 / WIDTH;
    start_x = data->player->angle - PI / 6;
    while (i < WIDTH)
    {
        debug_draw_ray(data, start_x, i);
        start_x += fraction;
        i++;
    }
    // DRAWS A SINGLE LINE
    // while (!touch(ray_x, ray_y, data))
    // {
    //     debug_put_pixel(ray_x, ray_y, 0xFF0000, data->debug);
    //     ray_x += cos_angle;
    //     ray_y += sin_angle;
    // }
    draw_loop(data);
    mlx_put_image_to_window(data->debug->mlx, data->debug->win, data->debug->img, 0, 0);
    return (0);
}

void debug_window(t_data *data)
{
    t_image_debug *image;

    image = malloc(sizeof(t_image_debug));

    data->player->key_up = false;
    data->player->key_down = false;
    data->player->key_left = false;
    data->player->key_right = false;
    
    data->player->x_pst = WIDTH / 2;
    data->player->y_pst = HEIGHT / 2;
    data->player->angle = PI / 2;
    data->player->left_rotate = false;
    data->player->right_rotate = false;
    data->debug = image;
    debug_init_debug(image);
    mlx_hook(image->win, KeyPress, KeyPressMask, debug_key_press, data);
    mlx_hook(image->win, KeyRelease, KeyReleaseMask, debug_key_release, data);
    mlx_loop_hook(image->mlx, debug_draw_loop, data);
    mlx_loop(image->mlx);
}