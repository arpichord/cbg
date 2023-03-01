#ifndef PIECE_H
#define PIECE_H

// Forward declarations
typedef struct Position Position;
typedef struct Association Association;
typedef struct Board Board;


typedef enum PIECE_TYPES {

    PIECE_CHESS_PAWN,
    PIECE_CHESS_KING,
    PIECE_CHESS_QUEEN,
    PIECE_CHESS_BISHOP,
    PIECE_CHESS_ROOK,
    PIECE_CHESS_KNIGHT

} PIECE_TYPE;

typedef enum PLAYER_NUMBERS {

    PLAYER_ONE,
    PLAYER_TWO,
    PLAYER_THREE,
    PLAYER_FOUR

} PLAYER_NUMBER;

typedef enum PIECE_STATES {

    PIECE_STATE_NOT_MOVED       = 1 << 0,
    PIECE_STATE_HAS_MOVED       = 1 << 1

} PIECE_STATE;

typedef enum Y_FLIP_VALUES {

    Y_FLIP_POSITIVE = 1,
    Y_FLIP_NEGATIVE = -1,
    Y_FLIP_NOT_SET = 10 // If you're getting values * 10, indication you forgot to set Y_FLIP explicitly for piece somehwere

} Y_FLIP_VALUE;

typedef struct Piece {

    PIECE_TYPE piece_type;
    PIECE_STATE state;
    PLAYER_NUMBER player_number;
    Association** associations;
    
    Position* position;
    Position* prev_position;

    int association_count;
    Y_FLIP_VALUE y_flip;
    
    int x;
    int y;

} Piece;

int init_piece(Piece** piece, PIECE_TYPE type, PLAYER_NUMBER player_number);
int _init_piece_chess(Piece* piece);

int place_piece(Board*, Piece*, int x, int y);
int remove_piece(Board*, Piece*);

int move_piece(Board* board, Piece* piece, int x, int y);


#endif