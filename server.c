#include <unistd.h>
#include <stdlib.h>


int main(int argc, char **argv){
    char* pid;
    int i;
    
    i = 0;
    if (argc == 3){
        pid = ft_atoi(argv[1]);
        while (argv[2][i] != '\0'){
            ft_atob(pid, argv[2][i]);
            i++;
        }
    else{
        ft_printf("Error\n");
        return(1);
    }
    while (1){

    }
    return (0);
    }
}

