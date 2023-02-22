
bin/cbg: main.o display.o game.o piece.o update.o board.o
	gcc $^ -o bin/cbg


main.o: main.c
display.o: display.c display.h
game.o: game.c game.h
piece.o: piece.c piece.h
update.o: update.c update.h
general.o: general.c general.h



clean:
	rm -f *.o
	rm -f bin/*