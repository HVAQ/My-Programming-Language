#include <stdio.h>

int main (void) {

    if ( (1 == 2) && (10 / 0 == 1))
        printf ("Hello world.\n");
    else
        printf ("World hello.\n");

    return 0;
}
