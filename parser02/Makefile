.PHONY: build

build: main
	./main

main: main.c tinyexpr.c tinyexpr.h
	gcc -W -Wall -std=c11 -pedantic -lm main.c tinyexpr.c -o main