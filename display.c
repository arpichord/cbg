#include <stdio.h>
#include <string.h>
#include "piece.h"
#include "board.h" 
#include "display.h"

int _display_CLI(Board* board) {
    
    Position* pos;
    char print_char = CLI_UNKNOWN;
    char print_fg_color[10] = {0};
    char print_bg_color[10] = {0};

    // Set base colores
    strcpy(print_fg_color, ANSI_COLOR_RESET);
    strcpy(print_bg_color, ANSI_COLOR_RESET);
    
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
                        strcpy(print_fg_color, PLAYER_1_COLOR);
                        break;
                    case PLAYER_TWO:
                        strcpy(print_fg_color, PLAYER_2_COLOR);
                    break;
                    case PLAYER_THREE:
                        strcpy(print_fg_color, PLAYER_3_COLOR);
                        break;
                    case PLAYER_FOUR:
                        strcpy(print_fg_color, PLAYER_4_COLOR);
                        break;
                    }
                }
            

            if (board->selected != NULL) {

                // Color BG Selected Data

                if (get_position(board, x, y) == board->selected) {

                    strcpy(print_bg_color, SELECTED_COLOR);

                }

                for (int i = 0; i < get_position(board, x, y)->association_count; i++) {
                    
                    Association* asc = get_position(board, x, y)->associations[i];
                  
                    if (asc->piece == board->selected->piece) {

                        if (asc->state & ASSOCIATION_STATE_VALID_MOVE == ASSOCIATION_STATE_VALID_MOVE)
                            strcpy(print_bg_color, STATE_COLOR_VALID_MOVE);
                            
                    }                        
                }
            }
            
            printf("%s %s", print_fg_color, print_bg_color);
            printf(" %c ", print_char);
            strcpy(print_fg_color, ANSI_COLOR_RESET);
            strcpy(print_bg_color, ANSI_COLOR_RESET);

        }

        printf("\n");
    }

}


int display(Board* board, DISPLAY_MODE mode) {

    switch(mode){
        case DISPLAY_MODE_CLI:
            _display_CLI(board);

    }
}