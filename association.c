#include <stdlib.h>
#include <stdio.h>

#include "association.h"
#include "board.h"
#include "piece.h"


    ////
    //
    //  Associations are links between pieces and positions with flag-based states.
    //  Both Piece and Position data structs have them.
    // 
    //  Interlinking allows keeping track of related data.
    //  Should be particularly helpful in the advent of 
    //  implementing bots / engines.
    //  
    ////


int add_association(Piece* piece, Position* pos, ASSOCIATION_STATE state) {

    // create new association object
    Association* asc = malloc(sizeof(Association));
    asc->piece = piece;
    asc->state = state;
    asc->position = pos;

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

int remove_association(Association* asc) {

    int                      index_start;
    Association*             pos_asc_p;
    Association*             piece_asc_p;


    // First remove from Position

    index_start = -1;

    for (int i_asc = 0; i_asc <= asc->position->association_count; i_asc++){

        if (asc->position->associations[i_asc] == asc) {
                    
            index_start = i_asc;
        
        }

        if (index_start != -1 && (i_asc + 1 < asc->position->association_count)) {
            
            asc->position->associations[index_start + (i_asc - index_start)] = asc->position->associations[i_asc+1];
            
        }

    }

    asc->position->association_count -= 1;

    asc->position->associations = realloc(asc->position->associations, sizeof(Association) * asc->position->association_count);

    // Then remove from piece on position

    index_start = -1;

    for (int i_asc = 0; i_asc <= asc->piece->association_count; i_asc++) {

        if (asc->piece->associations[i_asc] == asc) {

            index_start = i_asc;

        }

        if (index_start != -1 && (i_asc + 1 < asc->piece->association_count)) {
            
            asc->piece->associations[index_start + (i_asc - index_start)] = asc->piece->associations[i_asc+1];
            
        }

    }

    asc->piece->association_count -= 1;

    asc->piece->associations = realloc(asc->piece->associations, sizeof(Association)*asc->piece->association_count);

    free(asc);

    return 0;
}

int remove_piece_associations(Piece* piece) {

    while (piece->association_count != 0) {

        //printf("Count: %d\n", piece->association_count);
        //printf("Association: %p\n", piece->associations[0]);
        //remove_association(piece->associations[0]);
        remove_association(piece->associations[0]);

    }

    return 0;
}

int update_associations(Board* board, Piece* piece) {

    int x =             0;
    int y =             0;

    int y_flip =        piece->y_flip;
    
    Position*           pos;
    ASSOCIATION_STATE   asc_state;
    POSITION_STATE      pos_state;

    // Remove piece associations
    remove_piece_associations(piece);

    // Create new assocation at piece home
    add_association(piece, get_position(board, piece->x, piece->y), ASSOCIATION_STATE_HOME);

    switch (piece->piece_type) {

        case PIECE_CHESS_BISHOP:

            break;

        case PIECE_CHESS_KING:

            break;

        case PIECE_CHESS_QUEEN:

            break;

        case PIECE_CHESS_PAWN:

            // Pawn one space up
            
            x = piece->x;
            y = piece->y+(1*y_flip);
            
            if (!exceeds_bounds(board, x, y)) {

                pos = get_position(board, x, y);
                pos_state = pos->state;

                if (!((pos_state & POSITION_STATE_HAS_PIECE) == POSITION_STATE_HAS_PIECE)) {
                    
                    add_association(piece, pos, ASSOCIATION_STATE_VALID_MOVE);
                    
                } else {

                    add_association(piece, pos, ASSOCIATION_STATE_BLOCKED);
                }
            
            }
            
            // Pawn two spaces up

            y += 1*y_flip;


            if (!exceeds_bounds(board, x, y)) {
            
                pos = get_position(board, x, y);
                pos_state = pos->state;

                if ((piece->state & PIECE_STATE_NOT_MOVED) == PIECE_STATE_NOT_MOVED){

                    if (!((pos_state & POSITION_STATE_HAS_PIECE) == POSITION_STATE_HAS_PIECE)) {

                        add_association(piece, pos, ASSOCIATION_STATE_VALID_MOVE);

                    } else {

                        add_association(piece, pos, ASSOCIATION_STATE_BLOCKED);

                    }
                }

            }
            
            // Pawn attack right

            y = piece->y+(1*y_flip);
            x = piece->x+1;

            if (!exceeds_bounds(board, x, y)) {

                pos = get_position(board, x, y);
                pos_state = pos->state;

                // add strike association regardless, but also add valid move if valid

                if (((pos_state & POSITION_STATE_HAS_PIECE) == POSITION_STATE_HAS_PIECE) && 
                        pos->piece->player_number != piece->player_number){
                    
                    add_association(piece, pos, ASSOCIATION_STATE_STRIKE | ASSOCIATION_STATE_VALID_MOVE);                

                } else {

                    add_association(piece, pos, ASSOCIATION_STATE_STRIKE);

                }
            }

            // Pawn attack left

            x = piece->x-1;

            if (!exceeds_bounds(board, x, y)) {

                pos = get_position(board, x, y);
                pos_state = pos->state;

                // add strike association regardless, but also add valid move if valid

                if (((pos_state & POSITION_STATE_HAS_PIECE) == POSITION_STATE_HAS_PIECE) && pos->piece->player_number != piece->player_number){
                    
                    add_association(piece, pos, ASSOCIATION_STATE_STRIKE | ASSOCIATION_STATE_VALID_MOVE);                

                } else {

                    add_association(piece, pos, ASSOCIATION_STATE_STRIKE);
                    
                }

            }

            break;

        case PIECE_CHESS_ROOK:

            // Left
        
            y = piece->y;

            for (x = piece->x-1; x >= 0; x--) {

                pos = get_position(board, x, y);
                if (pos->state == POSITION_STATE_HAS_PIECE) {

                    if (pos->piece->player_number != piece->player_number)
                        add_association(piece, pos, ASSOCIATION_STATE_STRIKE | ASSOCIATION_STATE_VALID_MOVE);
                    else
                        add_association(piece, pos, ASSOCIATION_STATE_BLOCKED);
                    break;

                } else {
                    
                    add_association(piece, pos, ASSOCIATION_STATE_VALID_MOVE | ASSOCIATION_STATE_STRIKE);
                    
                }

            }

            // Right

            y = piece->y;

            for (x = piece->x+1; x < board->width; x++) {

                pos = get_position(board, x, y);
                if (pos->state == POSITION_STATE_HAS_PIECE) {

                    if (pos->piece->player_number != piece->player_number)
                        add_association(piece, pos, ASSOCIATION_STATE_STRIKE | ASSOCIATION_STATE_VALID_MOVE);

                    break;

                } else {
                    
                    add_association(piece, pos, ASSOCIATION_STATE_VALID_MOVE | ASSOCIATION_STATE_STRIKE);
                    
                }

            }

            // Up

            x = piece->x;

            for (y = piece->y-1; y >= 0; y--) {

                pos = get_position(board, x, y);
                if (pos->state == POSITION_STATE_HAS_PIECE) {

                    if (pos->piece->player_number != piece->player_number)
                        add_association(piece, pos, ASSOCIATION_STATE_STRIKE | ASSOCIATION_STATE_VALID_MOVE);

                    break;

                } else {
                    
                    add_association(piece, pos, ASSOCIATION_STATE_VALID_MOVE | ASSOCIATION_STATE_STRIKE);
                    
                }

            }

            // Down

            x = piece->x;

            for (y = piece->y+1; y < board->height; y++) {

                pos = get_position(board, x, y);
                if (pos->state == POSITION_STATE_HAS_PIECE) {

                    if (pos->piece->player_number != piece->player_number)
                        add_association(piece, pos, ASSOCIATION_STATE_STRIKE | ASSOCIATION_STATE_VALID_MOVE);

                    break;

                } else {
                    
                    add_association(piece, pos, ASSOCIATION_STATE_VALID_MOVE | ASSOCIATION_STATE_STRIKE);
                    
                }

            }

            break;

        case PIECE_CHESS_KNIGHT:
            
            break;  

    }

    return 0;
}

int update_associations_contextual(Board *board, Piece *piece) {

    update_associations(board, piece);

    // Current position

    for (int i_asc = 0; i_asc < piece->position->association_count; i_asc++) {

        update_associations(board, piece->position->associations[i_asc]->piece);

    }

    // Previous Position

    if (piece->prev_position != NULL) {
        for (int i_asc = 0; i_asc < piece->prev_position->association_count; i_asc++) {

            update_associations(board, piece->prev_position->associations[i_asc]->piece);

        }
    }
    
    return 0;
}
