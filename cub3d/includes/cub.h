#include "../libraries/libft/libft.h"

typedef struct s_texture
{
    char    *no_texture;
    char    *so_texture;
    char    *we_texture;
    char    *ea_texture;
    char    *f_texture;
    char    *c_texture;
}   t_texture;

typedef struct s_data
{
    void        *mlx;
    void        *win;
    t_texture   *texture;
}   t_data;

/***  FONT name: ANSI Shadow
██████╗  █████╗ ██████╗ ███████╗███████╗██████╗ 
██╔══██╗██╔══██╗██╔══██╗██╔════╝██╔════╝██╔══██╗
██████╔╝███████║██████╔╝███████╗█████╗  ██████╔╝
██╔═══╝ ██╔══██║██╔══██╗╚════██║██╔══╝  ██╔══██╗
██║     ██║  ██║██║  ██║███████║███████╗██║  ██║
╚═╝     ╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝  ╚═╝          
 */
int	check_walls_texture(t_data *data, char *file);
int	check_map(t_data *data, int argc, char **argv);

/***  FONT name: ANSI Shadow
██╗███╗   ██╗██╗████████╗
██║████╗  ██║██║╚══██╔══╝
██║██╔██╗ ██║██║   ██║   
██║██║╚██╗██║██║   ██║   
██║██║ ╚████║██║   ██║   
╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝        
 */

int create_window(t_data *data);