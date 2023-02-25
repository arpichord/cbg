#include <stdio.h>

#include "debug.h"
#include "board.h"
#include "piece.h"
#include "association.h"


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

void print_associations(Board* board) {

    // load up positions

    
    for (int i_pos = 0; i_pos < board->position_count; i_pos++){
        for (int i_asc = 0; i_asc < board->positions[i_pos].association_count; i_asc++) {
            printf("\nAssociation: %p\n   Position: %d,%d\n       State: %d\n     Piece: %p\n       State: %d\n\n",
                board->positions[i_pos].associations[i_asc],
                board->positions[i_pos].x, 
                board->positions[i_pos].y,
                board->positions[i_pos].state,
                board->positions[i_pos].associations[i_asc]->piece,
                board->positions[i_pos].associations[i_asc]->state
            );
        }
    }

}