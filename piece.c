#include "piece.h"

int setup_piece(Piece** piece, PIECE_TYPE type, PLAYER_NUMBER player_number){

    (*piece)->piece_type=type;
    (*piece)->player_number=player_number;

    return 0;
}

