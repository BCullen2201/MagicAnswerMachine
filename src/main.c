#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "randNumGen.h"

#define BUF 50

struct answerString {
    char string[BUF];
};

int sleep_ms(int ms) {
    usleep(ms * 1000);
}

const char * getAnswer() {
    int selection = getRandomNumber(-1,18);
    const int length = getRandomNumber(45,75);
    const int lenMinusOne = length - 1;
    int sleepTime = 10;
    char * answer;
    char answerArray[20][BUF] = {
        {"Yep, definitely"},
        {"Not sure, try again"},
        {"Don't rely on it"},
        {"Seems the answer is yes"},
        {"No doubt!"},
        {"Come back later"},
        {"I'm gonna say no"},
        {"I shouldn't say right now"},
        {"They're telling me no"},
        {"Absolutely, yes"},
        {"You can count on it"},
        {"The way it looks, yes"},
        {"Hard to judge currently"},
        {"It ain't looking good for you"},
        {"It's to be expected"},
        {"Focus and have another go"},
        {"I really doubt it"},
        {"It's looking good!"},
        {"Affirmative!"},
        {"They're saying yes"}
    };

    for (int i = 0; i < length; i++) {
        selection++;
        if (selection > 19) {
            selection = 0;
        }

        if (i != lenMinusOne) {
            printf("%s\n", answerArray[selection]);
            sleep_ms(sleepTime);
            sleepTime = sleepTime + 5;
        }

        system("clear");
    }

    answer = answerArray[selection];
    return answer;
}

int main() {
    struct answerString s1;
    strcpy(s1.string, getAnswer());

    printf("%s\n\n", s1.string);

    return 0;
}
