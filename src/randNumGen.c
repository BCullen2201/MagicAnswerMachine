#include <stdio.h>
#include <stdlib.h>
#include <sys/random.h>

#define BUFFER 20

int getRandomNumber(int MIN, int MAX) {
    if (MIN > MAX) {
        int holder = MIN;
        MIN = MAX;
        MAX = holder;
    }

    unsigned int number;
    ssize_t randomData = getrandom(&number, sizeof(number), 0);
    if (randomData == -1) {
        fprintf(stderr, "getrandom() failed\n");
        exit(1);
    }

    int result = (number % (MAX - MIN + 1)) + MIN;

    return result;
}
