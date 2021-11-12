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
    char buffername = 0;

    for(int i =0; i <= 9; i++) {
        name[i] = 0;
    }
 
    write(1, "Enter your name (Max 10 char) : ", 33);
    do {
        if(i <= 9) {
            read(0, &name[i], 1);
            buffername = name[i];
            if(buffername <= '`' && buffername >= '[' || buffername < 'A' || buffername > 'z' || buffername != ' ' && buffername != '\n') {
                write(2, "\tError :\n\tThis does not look like a name\n", 42);
                clear_stdin();
                return 84;
            }
            if(buffername < 'A' || buffername > 'z') {
                if(buffername != ' ' && buffername != '\n') {
                    write(2, "\tError :\n\tThis does not look like a name\n", 42);
                    clear_stdin();
                    return 84;
                }
            }
        }
        i++;
    } while(name[i-1] != '\n' && i < 11);

    if(i == 11) {
        clear_stdin();
    } else if(i == 1) {
        write(2, "\tError :\n\tEmpty name !\n", 24);
        return 84;
    } else {
        name[i-1] = 0;
    }

    write(1, "Hello ", 6);
    write(1, name, 10);
    write(1, "\n", 1);
}
