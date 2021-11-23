#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    char curdir[100000];
    size_t len = 100000;
    memset(curdir, 0, len);
    if (getcwd(curdir, len) == NULL) {
        perror("getcwd failed.");
    } else {
        printf("curdir: %s\n", curdir);
    }

    int f = open(".", O_RDONLY);
    if (f < 0) {
        perror("open file filed");
    }

    ssize_t rlen = 0;
    memset(curdir, 0, len);
    if ((rlen = read(f, curdir, len)) < 0) {
        perror("read curdir failed");
    } else {
        curdir[rlen] = 0;
        printf("read info: %s rlen: %ld\n", curdir, rlen);
    }

    if (chdir("/Users/sydnash/") < 0) {
        perror("chdir failed.");
    }

    memset(curdir, 0, len);
    if (getcwd(curdir, len) == NULL) {
        perror("getcwd failed.");
    } else {
        printf("curdir: %s\n", curdir);
    }

    if (fchdir(f) < 0) {
        perror("fchdir failed");
    }

    memset(curdir, 0, len);
    if (getcwd(curdir, len) == NULL) {
        perror("getcwd failed.");
    } else {
        printf("curdir: %s\n", curdir);
    }
    return 0;
}
