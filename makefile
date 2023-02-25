
bin/cbg: main.o display.o game.o piece.o board.o association.o debug.o general.o
	gcc $^ -o bin/cbg


main.o: 		main.c
display.o: 		display.c display.h
game.o: 		game.c game.h
piece.o: 		piece.c piece.h
general.o: 		general.c general.h
debug.o: 		debug.c debug.h
association.o:	association.c association.h



clean:
	rm -f *.o
	rm -f bin/*