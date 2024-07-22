#include "so_long.h"

int ex_ber(char *str, int i)
{
    if (str[i] == '.' && (str[i + 1] == 'b') && str[i + 2] == 'e'
        && str[i + 3] == 'r'  && str[i + 4] == '\0')
    {
        return 0;
    }
    return 1;
}

int open_fd(char *file) {
    int fd;
    
    fd = open(file, O_RDONLY);
    
    if (fd == -1) {
        return 1;
    }
    if (close(fd) == -1) {
        return 1;
    }
    return 0;
}

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
        if (e == 1 )
            write(2, "EXTENTION INCORRECT\n", 19);
        open_fd(file);
    }
    else
        write(2, "ARGUMENT INCORRECT\n", 19);
        
    return 0;
}


