#ifndef BOARD_H
#define BOARD_H

// Forward declartions
typedef struct Piece Piece;

typedef enum POSITION_STATES {

    POSITION_STATE_AVAILABLE        = 1 << 0,
    POSITION_STATE_DANGER           = 1 << 1,
    POSITION_STATE_HAS_PIECE        = 1 << 2
    
} POSITION_STATE;

typedef enum ASSOCIATION_STATES {
    
    ASSOCIATION_STATE_VALID_MOVE    = 1 << 0,
    ASSOCIATION_STATE_STRIKE        = 1 << 1,
    ASSOCIATION_STATE_BLOCKED       = 1 << 2,
    ASSOCIATION_STATE_HOME          = 1 << 3,
    ASSOCIATION_STATE_NULL          = 1 << 4

} ASSOCIATION_STATE;
    
typedef struct Association {

    Piece* piece;
    ASSOCIATION_STATE state;

} Association;

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

Position* get_position(Board*, int x, int y);

#endif