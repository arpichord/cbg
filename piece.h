#ifndef PIECE_H
#define PIECE_H

typedef enum PIECE_TYPES{

    CHESS_PAWN,
    CHESS_KING,
    CHESS_QUEEN,
    CHESS_BISHOP,
    CHESS_ROOK,
    CHESS_KNIGHT

} PIECE_TYPE;

typedef enum PLAYER_NUMBERS{

    PLAYER_ONE,
    PLAYER_TWO,
    PLAYER_THREE,
    PLAYER_FOUR

} PLAYER_NUMBER;


typedef struct {

    PIECE_TYPE piece_type;
    PLAYER_NUMBER player_number;

} Piece;

int setup_piece(Piece** piece, PIECE_TYPE type, PLAYER_NUMBER player_number);


#endif