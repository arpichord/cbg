#include <stdio.h>
#include <stdlib.h>

#include "association.h"
#include "board.h"
#include "piece.h"
#include "display.h"
#include "game.h"
#include "debug.h"


int main(int argc, char*argv[]) {

    // Display board
    Board* b;
    setup_board(&b, 8, 8);
    
    Piece* p;
    setup_piece(&p, PIECE_CHESS_PAWN, PLAYER_TWO);

    place_piece(b, p, 3, 3);

    //update_associations(b, p);

    select_position(b, 3, 3);
    display(b, DISPLAY_MODE_CLI);

    for (int i = 0; i < 50000; i++){
        add_association(p, get_position(b, 3, 3), ASSOCIATION_STATE_HOME);
        remove_association(get_position(b, 3, 3)->associations[0]);
    }

    //remove_piece_associations(p);

    print_associations(b);

    //print_associations(b);
    printf("DONE\n");
    getchar();

}