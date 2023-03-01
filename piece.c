#include <stdlib.h>
#include <stdio.h>

#include "display.h"
#include "piece.h"
#include "board.h"

int setup_piece(Piece** piece, PIECE_TYPE type, PLAYER_NUMBER player_number) {
    
    (*piece) = malloc(sizeof(Piece));
    (*piece)->associations = NULL;
    (*piece)->association_count = 0;
    (*piece)->x = 0;
    (*piece)->y = 0;
    (*piece)->y_flip = Y_FLIP_NOT_SET;
    (*piece)->piece_type=type;
    (*piece)->player_number=player_number;
    
    // Specific traits needed;

    _setup_piece_chess(*piece);

    return 0;
}

int _setup_piece_chess(Piece *piece) {
    
    PLAYER_NUMBER pnum = piece->player_number;

    if (pnum == PLAYER_ONE)
        piece->y_flip = Y_FLIP_NEGATIVE;
    else if (pnum == PLAYER_TWO)
        piece->y_flip = Y_FLIP_POSITIVE;
    else if (pnum == PLAYER_THREE)
        piece->y_flip = Y_FLIP_NEGATIVE;
    else if (pnum == PLAYER_FOUR)
        piece->y_flip = Y_FLIP_POSITIVE;


    return 0;
}

int place_piece(Board* board, Piece* piece, int x, int y) {

    Position* pos = get_position(board, x, y);

    (pos->piece) = piece;    
    piece->x = x;
    piece->y = y;

    // Ensure not exceeding board boundries

    if (y >= board->height || x >= board->width || y < 0 || x < 0) {
        
        printf("\n%sError: Exceeded Board boundry when placing piece! \nCoords: (%d,%d)\nPiece Type: (%d)%s\n",
        ANSI_COLOR_RED , x, y, piece->piece_type, ANSI_COLOR_RESET);

    }

    if ((pos->state & POSITION_STATE_AVAILABLE) == POSITION_STATE_AVAILABLE) {

        // Set position state from available to having a piece

        pos->state = pos->state & ~(POSITION_STATE_AVAILABLE) | POSITION_STATE_HAS_PIECE;

    }

    return 0;
}


int move_piece(Board* board, Piece* piece) {


    return 0;
}
