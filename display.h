#ifndef DISPLAY_H
#define DISPLAY_H

#include "board.h"
#include "piece.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"


typedef enum DISPLAY_MODES {

    DISPLAY_MODE_CLI,
    DISPLAY_MODE_GL2D,
    DISPLAY_MODE_GL3D

} DISPLAY_MODE;


typedef enum CLI_CHARS {

    CLI_CHESS_PAWN      = 'P',
    CLI_CHESS_KING      = 'K',
    CLI_CHESS_QUEEN     = 'Q',
    CLI_CHESS_BISHOP    = 'B',
    CLI_CHESS_KNIGHT    = 'H',
    CLI_CHESS_ROOK      = 'R',
    CLI_CHESS_AVAILABLE = '.',
    CLI_UNKNOWN        = '?'

} CLI_CHAR;



int _display_CLI(Board* board);

int display(Board* board, DISPLAY_MODE mode);

#endif