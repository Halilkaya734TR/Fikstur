all: compile run

compile:
	gcc -O3 -o fikstur.exe fikstur.c

run:
	./fikstur.exe