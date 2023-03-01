#include <stdlib.h>
#include <stdio.h>

#include "association.h"
#include "display.h"
#include "piece.h"
#include "board.h"

int init_piece(Piece** piece, PIECE_TYPE type, PLAYER_NUMBER player_number) {
    
    (*piece)                        = malloc(sizeof(Piece));
    (*piece)->associations          = NULL;
    (*piece)->association_count     = 0;

    (*piece)->x                     = 0;
    (*piece)->y                     = 0;

    (*piece)->y_flip                = Y_FLIP_NOT_SET;
    (*piece)->piece_type            = type;
    (*piece)->player_number         = player_number;
    (*piece)->state                 = PIECE_STATE_NOT_MOVED;
    (*piece)->position              = NULL;
    (*piece)->prev_position         = NULL;

    // Specific game/piece traits needed;

    _init_piece_chess(*piece);

    return 0;
}

int _init_piece_chess(Piece *piece) {
    
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

    } else {

        return 0;

    }

    piece->position = pos;

    update_associations(board, piece);

    // Update associations at position since new context

    update_associations_contextual(board, piece);

    return 0;
}


int move_piece(Board* board, Piece* piece, int x, int y) {

    Association* assocation;
    ASSOCIATION_STATE state;

    if (exceeds_bounds(board, x, y))
        return 0;

    Position* old_position = get_position(board, piece->x, piece->y);

    for (int i_asc = 0; i_asc < piece->association_count; i_asc++) {

        assocation = piece->associations[i_asc];
        state = assocation->state;
        
        if (!(assocation->position->x == x && assocation->position->y == y))
            continue;


        if ((state & ASSOCIATION_STATE_VALID_MOVE) == ASSOCIATION_STATE_VALID_MOVE) {
            printf("TRUE\n");
            old_position->piece = NULL;
            old_position->state = old_position->state & ~(POSITION_STATE_HAS_PIECE) | POSITION_STATE_AVAILABLE;

            piece->position = get_position(board, x, y);
            piece->position->piece = piece;
            piece->position->state = piece->position->state & ~(POSITION_STATE_AVAILABLE) | POSITION_STATE_HAS_PIECE;
            piece->prev_position = old_position;

            piece->x = x;
            piece->y = y;

            update_associations_contextual(board, piece);


            return 1;
        }
    }


    

    return 0;
}
