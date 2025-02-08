#include "../../includes/cub.h"

#include "../../includes/cub.h"

int get_pixel_color(t_data *data, int x, int y)
{
    int bpp, size_line, endian;
    char *data2 = mlx_get_data_addr(data->texture->no_texture, &bpp, &size_line, &endian);
    return *(int *)(data2 + (y * size_line + x * (bpp / 8)));
}

void draw_textures(t_data *data, int i, float ray_x, float ray_y, int side)
{
    float distance;
    float wall_height;
    int start_y;
    int end_y;

    distance = fixed_calculate_distance(data->player->x_pst, data->player->y_pst, ray_x, ray_y, data);
    wall_height = (BLOCK / distance) * (WIDTH / 2);
    start_y = (HEIGHT - wall_height) / 2;
    end_y = start_y + wall_height;

    int texwidth = 64;
    int texheight = 64;

    // Calculate the exact x-coordinate on the texture
    float wallX;
    if (side == 0) { // Parede vertical (colisão no eixo X)
        wallX = ray_y;
    } else { // Parede horizontal (colisão no eixo Y)
        wallX = ray_x;
    }
    wallX /= BLOCK;  // Normalizando para o tamanho do bloco
    wallX -= floor(wallX); // Pegando apenas a fração
    

    int texX = (int)(wallX * (float)texwidth);
    if (texX < 0) texX = 0;
    if (texX >= texwidth) texX = texwidth - 1;

    while (start_y < end_y)
    {
        int d = start_y * 256 - HEIGHT * 128 + wall_height * 128;
        int texY = ((d * texheight) / wall_height) / 256;
        if (texY < 0) texY = 0;
        if (texY >= texheight) texY = texheight - 1;

        int color = get_pixel_color(data, texX, texY);
        put_pixel(i, start_y, color, data);
        start_y++;
    }
}


/** DICTIONARY
 * 
 * WALLX --> Where the ray hit
 * SIDE --> Verify if the
 * perpWallDist --> Distance from player to the wall
 * get_pixel_color() --> Returns the expecific pixel texture
 * */
