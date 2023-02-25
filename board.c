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
            pos->associations = NULL;
            pos->association_count = 0;
            pos->x = x;
            pos->y = y;
            pos->state = POSITION_STATE_AVAILABLE;

        }
    }
}

Position* get_position(Board* board, int x, int y) {

    int mult_indexed = (board->width * y) + x;
    return &(board->positions[mult_indexed]);

}


int select_position(Board* b, int x, int y){
    
    b->selected = get_position(b, x, y);
    
    return 0;
}
