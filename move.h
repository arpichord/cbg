#ifndef H_MOVE
#define H_MOVE

// Forward Declarations
typedef struct Piece Piece;
typedef struct Board Board;

int move_piece(Board* board, Piece* piece);
int update(Board* board, Piece* piece);
int _update_valid_moves(Board* board, Piece* piece);
int _update_position_association(Board* board, Piece* piece);

#endif