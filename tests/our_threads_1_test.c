#include "fs/operations.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

char *path_file = "/f1";

void *test_open(void *arg) {
    (void) arg;
    int f1;
    f1 = tfs_open(path_file, TFS_O_TRUNC | TFS_O_CREAT);
    assert(f1!=-1);
    return NULL;
}

int main() {

    pthread_t th1, th2;

    assert(pthread_create(&th1,NULL,test_open,NULL)==0);
    assert(pthread_create(&th2,NULL,test_open,NULL)==0);

    pthread_join(th1,NULL);
    pthread_join(th2,NULL);

    return 0;
}