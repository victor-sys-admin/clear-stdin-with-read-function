# clear-stdin-with-read-function
Wipe the stdin buffer with low level function read() so without &lt;stdio.h> and his function getchar()

## Why ?
To practise with low level functions

## Why use it ?
It's a simple alternative if you don't want to use &lt;stdio.h> and his function getchar() and if you already use &lt;unistd.h> in your main file.

When you got data in your stdin buffer, on your next read(), the buffer will automatically empty.

Wipe the stdin buffer will keep your future read() or (terminal if you don't have next read()) from an error that looks like an overflow.

## How to use it ?

To use read() it's recommanded to import &lt;unistd.h> so put it on your main file :

    #include <unistd.h>
Then import clear_stdin.h :

    #include "clear_stdin.h"
Finally use it :

    clear_stdin();
To get a deeper comprension of the function try it with test.c file.
