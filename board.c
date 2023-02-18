#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "piece.h"


int setup_board(Board** board, int width, int height) {

    *board = malloc(sizeof(Board));
    (*board)->height = height;
    (*board)->width = width;
    (*board)->position_count = width*height;
    (*board)->positions = malloc(sizeof(Position)*((*board)->position_count));

    Position* pos;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            
            pos = get_position((*board), x, y);
            pos->state = POSITION_STATE_AVAILABLE;

            pos->piece = NULL;
            pos->piece_associations = NULL;
        }
    }
    
    return 0;
}

Position* get_position(Board* board, int x, int y) {

    int mult_indexed = board->height * y + x;
    return &(board->positions[mult_indexed]);

}

int place_piece(Board* board, Piece* piece, int x, int y) {

    Position* pos = get_position(board, x, y);

    (pos->piece) = piece;    
    if (pos->state & POSITION_STATE_AVAILABLE == POSITION_STATE_AVAILABLE) {
        pos->state = (pos->state & (~POSITION_STATE_AVAILABLE)) | POSITION_STATE_HAS_PIECE;
    }

};