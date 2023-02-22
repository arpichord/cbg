#include <stdio.h>
#include <stdlib.h>

#include "board.h"
#include "piece.h"
#include "display.h"
#include "game.h"
#include "update.h"

int main(int argc, char*argv[]) {

    // Display board
    Board* b;
    setup_board(&b, 8, 8);
    
    Piece* p;
    setup_piece(&p, PIECE_CHESS_PAWN, PLAYER_TWO);

    place_piece(b, p, 3, 3);

    update(b, p);

    //print_bits(get_position(b, 3, 3)->state);

    //set_position_state(get_position(b, 3, 3), !POSITION_STATE_HAS_PIECE);

    display(b, DISPLAY_MODE_CLI);


}