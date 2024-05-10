stringMe: stringUtils.o main.o
	gcc -Wall -std=c99 main.o stringUtils.o -o stringMe

stringUtils.o: stringUtils.c functionHeaders.h
	gcc -Wall -std=c99 -c stringUtils.c

main.o: main.c functionHeaders.h
	gcc -Wall -std=c99 -c main.c

clean:
	rm *.o stringMe
