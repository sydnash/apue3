#include <unistd.h>
#include <stdio.h>

typedef struct _a {
    char a;
    double b;
    char c;
}A;

int main(void) {
    printf("sizeof a: %d\n", sizeof(A));
    // on macos, sbrk has a maximum allocation of 4M
    char* p1 = (char*)sbrk(0);
    printf("p1 pos : %p\n", &p1);
    int cnt = 0;
    printf("cnt pos : %p\n", &cnt);
    int n = (int)p1;
    printf("n: %p %d\n", &n, (int)(&cnt - &n));
    while ((int)p1 > 0) {
        p1 = sbrk(1024*1024);
        cnt++;

        printf("sbrk times: %d %p %d\n", cnt, p1, (int)p1);
    }
    perror("sbrk failed: ");

    /* on macos, brk always failed.
    *(p1+1024*1024) = 0;
    char* p2 = (char*)brk(p1+1); 
    if ((int)p2 < 0) {
        perror("brk failed: ");
    }
    */

    printf("end %p\n", p1);
}
