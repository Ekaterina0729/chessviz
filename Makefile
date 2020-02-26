all:lounch
comp: Chess.c
	gcc -Wall -o Chess Chess.c
lounch: comp
	./Chess

