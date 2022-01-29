#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    srand(time(NULL));
    printf("forking around\n");

    int x = fork();
    int y;

    if (x) {
        y = fork();
        rand();
    }

    if (x && y) {
        int status;
        int cpid = wait(&status);
        int t = WEXITSTATUS(status);

        printf("%d, %d\n", cpid, t);
        printf("parent is done\n");

    }
    else {
        printf("%d\n", getpid());
        int s = rand() % 4  + 2;
        sleep(s);
        printf("child is done\n");

        return s;
    }

    return 0;

}
