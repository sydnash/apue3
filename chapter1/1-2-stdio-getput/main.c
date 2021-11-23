#include <stdio.h>

int main(void) {
    char c;
    while ((c = getc(stdin)) != EOF) {
        if (putc(c, stdout) == EOF) {
            return -1;
        }
    }

    if (ferror(stdin)) {
        return -1;
    }

    return 0;
}
