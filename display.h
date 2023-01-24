#ifndef DISPLAY_H
#define DISPLAY_H

#include "board.h"
#include "piece.h"


typedef enum DISPLAY_MODES {
    DISPLAY_MODE_CLI,
    DISPLAY_MODE_GL2D,
    DISPLAY_MODE_GL3D
} DISPLAY_MODE;

int _display_CLI(Board* board);

int display(Board* board, DISPLAY_MODE mode);

#endif