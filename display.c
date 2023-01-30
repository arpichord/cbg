#include <stdio.h>
#include "display.h"


int _display_CLI(Board* board) {
    
    Position* pos;
    char print_char = CLI_DEFAULT;

    for (int y = 0; y < board->height; y++) {

        for (int x = 0; x < board->width; x++) {
 
            pos = get_position(board, x, y);
            
            // Check if piece at location
            if (pos->state & POSITION_STATE_AVAILABLE) {
                
                print_char = CLI_CHESS_AVAILABLE;

            } else {
                switch (pos->piece->piece_type){
                    case CHESS_PAWN:
                        print_char = CLI_CHESS_PAWN;
                        break;
                    case CHESS_BISHOP:
                        print_char = CLI_CHESS_BISHOP;
                        break;
                    case CHESS_KNIGHT:
                        print_char = CLI_CHESS_KNIGHT;
                        break;
                    case CHESS_KING:
                        print_char = CLI_CHESS_KING;
                        break;
                    case CHESS_ROOK:
                        print_char = CLI_CHESS_ROOK;
                        break;
                    case CHESS_QUEEN:
                        print_char = CLI_CHESS_QUEEN;
                        break;
                }
            }
            
            printf(" %c ", print_char);
        }
        printf("\n");
    }

};

int display(Board* board, DISPLAY_MODE mode) {

    switch(mode){
        case DISPLAY_MODE_CLI:
            _display_CLI(board);

    }
};