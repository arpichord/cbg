#ifndef BOARD_H
#define BOARD_H

#include <stdlib.h>
#include "piece.h"

typedef enum POSITION_STATES{

    POSITION_STATE_AVAILABLE = 1 >> 0,
    POSITION_STATE_DANGER = 1 >> 1,
    POSITION_STATE_HAS_PIECE = 1 >> 2
    
} POSITION_STATE;

    
typedef struct {

    POSITION_STATE state;
    Piece* piece;
    Piece* piece_associations;

} Position;

typedef struct {
    
    int width;
    int height;
    int position_count;
    Position* positions;

} Board;


int setup_board(Board**, int width, int height);

int add_piece_association(Position*, Piece*);
int remove_piece_association(Position*, Piece*);

int remove_piece(Board*, Piece*);

int place_piece(Board*, Piece*, int x, int y);

Position* get_position(Board*, int x, int y);

#endif