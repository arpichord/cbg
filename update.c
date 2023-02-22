#include <stdlib.h>
#include <stdio.h>

#include "board.h"
#include "piece.h"
#include "update.h"


void print_bits(unsigned int num)
{
    printf("--- BITS ---\n");
    for(int bit=0;bit<(sizeof(unsigned int) * 8); bit++)
    {
        printf("%i ", num & 0x01);
        num = num >> 1;
   }
   printf("\n--- BITS ---\n");
}

int update(Board* board, Piece* piece) {

    switch (piece->piece_type) {
        case PIECE_CHESS_BISHOP:
            break;
        case PIECE_CHESS_KING:
            break;
        case PIECE_CHESS_QUEEN:
            break;
        case PIECE_CHESS_PAWN:

            // If no piece, add associations ( this needs to be cleaner. Do specific maths; less long check code)
            if (!((get_position(board, piece->x, piece->y+1)->state & POSITION_STATE_HAS_PIECE) == POSITION_STATE_HAS_PIECE)) {
                
                add_association(piece, get_position(board, piece->x, piece->y+1), ASSOCIATION_STATE_VALID_MOVE);
                
            }

            if (!((get_position(board, piece->x, piece->y+2)->state & POSITION_STATE_HAS_PIECE) == POSITION_STATE_HAS_PIECE)) {

                add_association(piece, get_position(board, piece->x, piece->y+2), ASSOCIATION_STATE_VALID_MOVE);
            }

            break;
        case PIECE_CHESS_ROOK:
            break;
        case PIECE_CHESS_KNIGHT:
            break;  
    }


    return 0;
}

int remove_piece_association(Position*, Piece*) {


    return 0;
}

int add_association(Piece* piece, Position* pos, ASSOCIATION_STATE state) {

    ////
    //
    //  Associations are links between pieces and positions
    //  Pieces and Positions share these as endpoints to suss out information conveniently
    //  living in memory. A piece has all it
    //
    ////

    // create new association object
    Association* asc = malloc(sizeof(Association));
    asc->piece = piece;
    asc->state = state;

    // Link Piece
    piece->association_count+=1;
    piece->associations = realloc(piece->associations, piece->association_count*sizeof(Association*));
    piece->associations[piece->association_count-1] = asc;

    // Link Position
    pos->association_count+=1;
    pos->associations = realloc(pos->associations, pos->association_count*sizeof(Association*));
    pos->associations[pos->association_count-1] = asc;

    return 0; 
}

int remove_position_link(Board* board, Piece* piece) {


    return 0;
}

int move_piece(Board* board, Piece* piece) {


    return 0;
}

int place_piece(Board* board, Piece* piece, int x, int y) {

    Position* pos = get_position(board, x, y);

    (pos->piece) = piece;    
    piece->x = x;
    piece->y = y;

    if (pos->state & POSITION_STATE_AVAILABLE == POSITION_STATE_AVAILABLE) {

        // Set position state from available to having a piece
        pos->state = pos->state & ~(POSITION_STATE_AVAILABLE) | POSITION_STATE_HAS_PIECE;

    }

    return 0;
}

int update_piece_associations(Board* board, Piece* piece) {

 
    return 0;
}

int set_position_state(Position* pos, POSITION_STATE flag, FLAG_SET_TYPE type) {

    if (type == FLAG_SET_TYPE_ENABLE)
        pos->state |= flag;

    else if (type == FLAG_SET_TYPE_DISABLE)
        pos->state &= ~flag;

}

int set_association_state(Association* asc, ASSOCIATION_STATE flag);