#include "../../includes/cub.h"

typedef struct s_image {
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}   t_image;

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
    int x;
    int y;

    int tile_size = 32; // Tamanho de cada "quadrado" no mapa
    int color = 0xFFFFFF; // Cor branca para as paredes

    //printf("Iniciando desenho do mapa...\n");  // Depuração

    x = 0;
    while (data->map->matrix[x]) { // Percorre as linhas do mapa
        y = 0;
        while (data->map->matrix[x][y]) { // Percorre as colunas do mapa
            if (data->map->matrix[x][y] == '1') { // Se for parede
                //printf("Desenhando parede na posição (%d, %d)\n", x, y);  // Depuração
                draw_square(image, y * tile_size, x * tile_size, tile_size, color);
            }
            y++;
        }
        x++;
    }

    // Depois de desenhar todos os quadrados, podemos copiar a imagem para a janela
    mlx_put_image_to_window(mlx, win, image->img, 0, 0);
}



void debug_window(t_data *data)
{
	void *mlx;
	void *win;
	t_image *image;

	image = malloc(sizeof(t_image));
	mlx = mlx_init();
	//mlx_get_screen_size
	win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Debug");
	initialize_image(data, image);
	(void)mlx;
	(void)win;
	draw_map(data, image, mlx, win);

}