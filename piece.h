#ifndef PIECE_H
#define PIECE_H

// Forward declarations
typedef struct Position Position;

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


typedef struct Piece {

    PIECE_TYPE piece_type;
    PLAYER_NUMBER player_number;
    Position* position_associations;

} Piece;

int setup_piece(Piece** piece, PIECE_TYPE type, PLAYER_NUMBER player_number);


#endif