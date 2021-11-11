/*
** Victor, 2021
** test.c
** File description:
** hello $name (low level)
*/
#include <unistd.h>
#include "clear_stdin.h"
 
int main() {
    char name[10];
    int i = 0;

    write(1, "Enter your name (Max 10 char) : ", 33);

    read(0, &name[i], 1);
    i++;
    while(name[i-1] != '\n' && i < 10) {
        read(0, &name[i], 1);
        i++;
    }
    
    if(i == 10) {
        clear_stdin();
        write(1, "Hello ", 6);
        write(1, name, 10);
        write(1, "\n", 1);
        return 0;
    }
    
    name[i-1] = 0;
    if(name[0] == 0) {
        write(2, "\tError :\n\tEmpty name !\n", 24);
        return 84;
    } else {
        write(1, "Hello ", 6);
        write(1, name, 10);
        write(1, "\n", 1);
        return 0;
    }
}
