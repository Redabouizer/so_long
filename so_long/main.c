#include "so_long.h"

int main(int ac, char *av[])
{
    char *file;
    int i;
    int e;

    if (ac == 2)
    {
        file = av[1]; 
        i = 0;
        e = 1;
        while (file[i])
        {
            if ((e = ex_ber(file, i)) == 0)
                break; 
            i++;
        }
        if (e == 1 || ft_stack(file) == -1)
           return (ft_putendl_fd("INCORRECT", 2), 1); 
    }
    else
        return (ft_putendl_fd("ARGUMENT INCORRECT", 2), 1);
    return 0;
}
