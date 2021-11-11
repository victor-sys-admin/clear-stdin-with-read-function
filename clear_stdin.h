/*
** Victor, 2021
** clear_stdin.h
** File description:
** wipe data from stdin buffer
*/

void clear_stdin(void) {
    char c = 0;
    while(c != '\n' && c != -1) {
        read(1, &c, 1);
    }
}
