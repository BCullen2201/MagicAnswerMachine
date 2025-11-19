dirs:
	mkdir ./bin; mkdir ./test

all:
	gcc -o ./bin/app ./src/main.c

run:
	./bin/app

debug:
	gcc -g -o ./test/prog ./src/main.c

rundebug:
	gdb ./test/prog

memcheck:
	valgrind -s --leak-check=full --track-origins=yes ./test/prog

clean:
	rm -r ./bin; rm -r ./test
