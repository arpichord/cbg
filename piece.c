#include <stdlib.h>
#include "piece.h"

int setup_piece(Piece** piece, PIECE_TYPE type, PLAYER_NUMBER player_number) {
    
    (*piece) = malloc(sizeof(Piece));
    (*piece)->associations = NULL;
    (*piece)->association_count = 0;
    (*piece)->x = 0;
    (*piece)->y = 0;
    (*piece)->piece_type=type;
    (*piece)->player_number=player_number;
    

    return 0;
}

