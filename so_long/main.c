#include "so_long.h"

int ex_ber(char *str, int i)
{
    if (str[i] == '.' && str[i + 1] == 'b' && str[i + 2] == 'e'
        && str[i + 3] == 'r' && str[i + 4] == '\0')
    {
        return 0; 
    }
    return 1; 
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
        if (e == 1)
            write(2, "EXTENSION INCORRECT\n", 19); 
        if (read_fd(open_fd(file))==1)
            write(2, "INCORRECT\n", 10); ; 
    }
    else
        write(2, "ARGUMENT INCORRECT\n", 19); 
        
    return 0;
}
