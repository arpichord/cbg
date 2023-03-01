#ifndef BOARD_H
#define BOARD_H

// Forward declartions
typedef struct Piece Piece;
typedef struct Association Association;
 

typedef enum POSITION_STATES {

    POSITION_STATE_AVAILABLE        = 1 << 0,
    POSITION_STATE_DANGER           = 1 << 1,
    POSITION_STATE_HAS_PIECE        = 1 << 2
    
} POSITION_STATE;

typedef struct Position {

    POSITION_STATE state;
    Piece* piece;
    Association** associations;
    int x;
    int y;
    int association_count;

} Position;

typedef struct Board {
    
    int width;
    int height;
    int position_count;
    Position* selected;
    Position* positions;

} Board;


int setup_board(Board**, int width, int height);
int deconstruct_board(Board** board);

int select_position(Board* b, int x, int y);

Position* get_position(Board*, int x, int y);

int exceeds_bounds(Board* b, int x, int y);

#endif