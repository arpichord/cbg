#ifndef DISPLAY_H
#define DISPLAY_H

#include "board.h"
#include "piece.h"


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
    CLI_DEFAULT         = '?'


} CLI_CHAR;

int _display_CLI(Board* board);

int display(Board* board, DISPLAY_MODE mode);

#endif