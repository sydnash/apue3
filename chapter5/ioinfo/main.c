#include <stdio.h>

void pr_stdio(const char* name, FILE *fp) {
    printf("stream = %20.15s, flags: %10d ", name, fp->_flags);

    short flags = fp->_flags & 0x3;
    printf("flags: %5d   ", flags);
    if (flags == _IOFBF) {
        printf("%15s","fully buffer");
    } else if (flags == _IOLBF) {
        printf("%15s", "line buffer");
    } else {
        printf("%15s", "nobuffer");
    }

    printf(", buffer size = %20d\n", fp->_bf._size);
}

int main() {
    fputs("enter any info\n", stdout);
    if (fgetc(stdin) == EOF) {
        perror("getchar error");
    }
    fputs("one line to standard error\n", stderr);

    pr_stdio("stdin", stdin);
    pr_stdio("stdout", stdout);
    pr_stdio("stderr", stderr);

    FILE *fp;
    if ((fp = fopen("/etc/hosts", "r")) == NULL) {
        perror("open file error.");
    }
    if (fgetc(fp) == EOF) {
        perror("open file error.");
    }

    pr_stdio("/etc/hosts", fp);
}
