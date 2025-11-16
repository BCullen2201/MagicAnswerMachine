#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int getRandomNumber(int MIN, int MAX) {
	if (MIN > MAX) {
		int holder = MIN;
		MIN = MAX;
		MAX = holder;
	}

	const int BUFFER = 20;
	int randomData = open("/dev/urandom", O_RDONLY);
	if (randomData == -1) {
		fprintf(stderr, "Could not open '/dev/urandom'\n");
		exit(1);
	}
	unsigned int result[BUFFER];

	read(randomData, result, BUFFER);
	close(randomData);

	int number = (*result % (MAX - MIN + 1)) + MIN;

	return number;
}
