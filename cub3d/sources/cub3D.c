#include "../includes/cub.h"

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
	if (check_map(argc, argv) == -1)
		return (-1);
	else
		printf("Configuração certa\n");
}