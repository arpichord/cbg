
bin/cbg: main.o display.o game.o piece.o move.o board.o
	gcc $^ -o bin/cbg


main.o: main.c
display.o: display.c
game.o: game.c
piece.o: piece.c
move.o: move.c

clean:
	rm -f *.o
	rm -f bin/*