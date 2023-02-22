#include <stdio.h>
#include "piece.h"
#include "board.h" 
#include "display.h"

int _display_CLI(Board* board) {
    
    Position* pos;
    char print_char = CLI_UNKNOWN;

    
    for (int y = 0; y < board->height; y++) {

        for (int x = 0; x < board->width; x++) {

            pos = get_position(board, x, y);
            
            // Check if piece at location
            if (pos->state & POSITION_STATE_AVAILABLE) {
                
                print_char = CLI_CHESS_AVAILABLE;

            } else {

                switch (pos->piece->piece_type){
                    case PIECE_CHESS_PAWN:
                        print_char = CLI_CHESS_PAWN;
                        break;
                    case PIECE_CHESS_BISHOP:
                        print_char = CLI_CHESS_BISHOP;
                        break;
                    case PIECE_CHESS_KNIGHT:
                        print_char = CLI_CHESS_KNIGHT;
                        break;
                    case PIECE_CHESS_KING:
                        print_char = CLI_CHESS_KING;
                        break;
                    case PIECE_CHESS_ROOK:
                        print_char = CLI_CHESS_ROOK;
                        break;
                    case PIECE_CHESS_QUEEN:
                        print_char = CLI_CHESS_QUEEN;
                        break;
                }

                //
                // Change Color for player num
                //

                switch (pos->piece->player_number){

                case PLAYER_ONE:
                    printf("%s", ANSI_COLOR_CYAN);
                    break;
                case PLAYER_TWO:
                    printf("%s", ANSI_COLOR_RED);
                   break;
                case PLAYER_THREE:
                    printf("%s", ANSI_COLOR_BLUE);
                    break;
                case PLAYER_FOUR:
                    printf("%s", ANSI_COLOR_GREEN);
                    break;
                    
                }
            }
            
            printf(" %c ", print_char);
            printf("%s", ANSI_COLOR_RESET);
        }
        printf("\n");
    }

};


int select_position(Board* b, int x, int y){
    
    
    return 0;
}

int display(Board* board, DISPLAY_MODE mode) {

    switch(mode){
        case DISPLAY_MODE_CLI:
            _display_CLI(board);

    }
};