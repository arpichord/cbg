#include <stdio.h>
#include <stdlib.h>

#include "board.h"
#include "piece.h"
#include "display.h"
#include "game.h"

int main(int argc, char*argv[]){

    // Display board
    Board* b;
    setup_board(&b, 8, 8);
    
    display(b, DISPLAY_MODE_CLI);
    

    



}