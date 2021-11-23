#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int main(void) {
    int i = 10;
    while (i > 0) {
        int fd = open("/dev/null", O_RDONLY);
        printf("open file fd: %d\n", fd);
        i--;
    }

    close(10);
    int fd = dup(0);
    printf("expect dup fd is 10, get: %d\n", fd);


    fd = dup2(0, 20);
    printf("expect dup2 fd is 20, get: %d\n", fd);

    close(12);
    fd = dup2(0, 11);
    printf("expect dup2 fd is 11, get: %d\n", fd);

    close(11);
    fd = fcntl(0, F_DUPFD, 22);
    printf("expect fcntl 22 fd is 22, get: %d\n", fd);

    fd = fcntl(0, F_DUPFD, 3);
    printf("expect fcntl 3 fd is 11, get: %d\n", fd);

    close(fd);

    char a[10];
    ssize_t n = read(0, a, 5);
    printf("expect 5 get %zd\n", n);
}
