#include "../../includes/cub.h"


void my_mlx_pixel_put(t_image *image, int x, int y, int color) {
    char    *dst;

    dst = image->addr + (y * image->line_length + x * (image->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

void initialize_image(t_data *data, t_image *image) {
    image->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);  // Cria uma nova imagem
    if (!image->img) {
        exit(EXIT_FAILURE); // Se falhar ao criar a imagem
    }

    // Obtém as informações da imagem (endereço, bits por pixel, largura da linha, endianess)
    image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel,
                                         &image->line_length, &image->endian);
    if (!image->addr) {
        exit(EXIT_FAILURE); // Se falhar ao obter os dados da imagem
    }
}

void draw_square(t_image *image, int start_x, int start_y, int size, int color) {
    int x;
    int y;

    // Acesso à estrutura da imagem associada

    //printf("Desenhando quadrado em (%d, %d) de tamanho %d\n", start_x, start_y, size);  // Depuração

    y = start_y;
    while (y < start_y + size) { // Controla as linhas do quadrado
        x = start_x;
        while (x < start_x + size) { // Controla as colunas do quadrado
            my_mlx_pixel_put(image, x, y, color); // Desenha o pixel na imagem
            x++;
        }
        y++;
    }
}

void draw_map(t_data *data, t_image *image, void *mlx, void *win) {
    int x, y;
    int tile_size = 32;
    int color = 0xFFFFFF;

    x = 0;
    while (data->map->matrix[x]) {
        y = 0;
        while (data->map->matrix[x][y]) {
            if (data->map->matrix[x][y] == '1') {
                draw_square(image, y * tile_size, x * tile_size, tile_size, color);
            }
            else if (data->map->matrix[x][y] == 'N') {
                // Posição atual do player em pixels
                int player_pixel_x = data->player->x_pst * tile_size;
                int player_pixel_y = data->player->y_pst * tile_size;

                int player_size = 16; // Tamanho do quadrado do player
                int offset = (tile_size - player_size) / 2;
                draw_square(image, player_pixel_y + offset, player_pixel_x + offset, player_size, 0xFF0000);
            }
            y++;
        }
        x++;
    }
    mlx_put_image_to_window(mlx, win, image->img, 0, 0);
}


void clear_image(t_image *image) {
    ft_bzero(image->addr, HEIGHT * image->line_length); // Limpa a imagem inteira
}

static int key_press_debug(int key_pressed, t_data *data)
{
    if (key_pressed == A)
    {
        printf("entrou para desenhar a nova posicao do player:  player y %f\n", data->player->y_pst);

        // Atualiza a posição do jogador
        data->player->y_pst -= 0.5;

        // Limpa a imagem antes de redesenhar
        clear_image(data->image);

        // Redesenha o mapa com a nova posição do jogador
        draw_map(data, data->image, data->image->mlx, data->image->win);
    }
    if (key_pressed == S)
        data->player->x_pst += 0.5;
    if (key_pressed == D)
        data->player->y_pst += 0.5;
    if (key_pressed == W)
        data->player->x_pst -= 0.5;
    clear_image(data->image);
    draw_map(data, data->image, data->image->mlx, data->image->win);
    return (0);
}

static void gameplay_debug(t_data *data, void *win)
{
    mlx_hook(win, KeyPress, KeyPressMask, key_press_debug, data);
}

void debug_window(t_data *data)
{
    t_image *image;

    image = malloc(sizeof(t_image));
    image->mlx = mlx_init();
    image->win = mlx_new_window(image->mlx, WIDTH, HEIGHT, "Debug");
    initialize_image(data, image);
    data->image = image;

    draw_map(data, image, image->mlx, image->win);
    gameplay_debug(data, image->win);

    mlx_loop(image->mlx);
}