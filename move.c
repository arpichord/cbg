#include <stdlib.h>
#include "board.h"
#include "piece.h"

int move_piece(Board* board, Piece* piece) {



};

int update(Board* board, Piece* piece) {

    piece->position_associations = NULL;
    

    switch (piece->piece_type) {
        case PIECE_CHESS_BISHOP:
            break;
        case PIECE_CHESS_KING:
            break;
        case PIECE_CHESS_QUEEN:
            break;
        case PIECE_CHESS_PAWN:
            break;
        case PIECE_CHESS_ROOK:
            break;
        case PIECE_CHESS_KNIGHT:
            break;  
    }

};