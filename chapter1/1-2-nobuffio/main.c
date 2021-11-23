#include <unistd.h>

#define BUFFSIZE 4096

int main(void) {
    int n = 0;
    char buff[BUFFSIZE];
    while ((n = read(STDIN_FILENO, buff, BUFFSIZE)) > 0) {
        if (write(STDOUT_FILENO, buff, n) != n) {
            return -1;
        }
    }
    if (n < 0) {
        return -1;
    }

    return 0;
}
