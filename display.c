#include <stdio.h>
#include "display.h"

typedef enum CLI_CHARS{
    CLI_CHESS_PAWN = 'C',
    CLI_CHESS_KING = 'K',
    CLI_CHESS_QUEEN = 'Q',
    CLI_CHESS_BISHOP = 'B',
    CLI_CHESS_KNIGHT = 'H',
    CLI_CHESS_ROOK = 'R',
    CLI_CHESS_AVAILABLE = '.'
} CLI_CHAR;

int _display_CLI(Board* board){

    Position* pos;
    for (int y = 0; y < board->height; y++){
        for (int x = 0; x < board->width; x++){
   
            pos = get_position(board, x, y);
            
            // Check if piece on location
            if (pos->state & POSITION_STATE_AVAILABLE){
                printf(" %c ", CLI_CHESS_AVAILABLE);
            } else {
                printf(" x ");
            }
        }
        printf("\n");
    }

};

int display(Board* board, DISPLAY_MODE mode){

    switch(mode){
        case DISPLAY_MODE_CLI:
            _display_CLI(board);

    }
};