#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFSIZE 4096

int main(void) {
    char buf[] = "abcdefghij";

    mode_t old = umask(0777); 
    umask(old);

    printf("real permision is: %o\n", 0666 & ~old);

    // file's real permision is 0666 & ~umask, where umask can be get from umask command.
    int fd = open("./testfile", O_RDWR|O_APPEND|O_CREAT, 0666);
    if (fd < 0) {
        perror("open failed: ");
        return 0;
    }

    if (write(fd, buf, 10) != 10) {
        perror("write failed: ");
        return 0;
    }

    off_t off;
    if ((off = lseek(fd, 0, SEEK_SET)) == -1) {
        perror("lseek failed: ");
        return 0;
    } else {
        printf("cur pos: %lld\n", off);
    }

    if (write(fd, buf, 10) != 10) { //open with O_APPEND, write always write to end.
        perror("write failed: ");
        return 0;
    }

    close(fd);
}
