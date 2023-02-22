#ifndef H_UPDATE
#define H_UPDATE

typedef enum FLAG_SET_TYPES {

    FLAG_SET_TYPE_ENABLE = 1 << 0,
    FLAG_SET_TYPE_DISABLE = 1 << 1,
    
} FLAG_SET_TYPE;

// Forward Declarations
typedef struct Piece Piece;
typedef struct Board Board;

int move_piece(Board* board, Piece* piece);

int update(Board* board, Piece* piece);
int _update_valid_moves(Board* board, Piece* piece);
int _update_position_association(Board* board, Piece* piece);
int _update_piece_associations(Board* board, Piece* piece);

int set_position_state(Position* pos, POSITION_STATE flag, FLAG_SET_TYPE type);
int set_association_state(Association* asc, ASSOCIATION_STATE flag);

int add_piece_association(Position*, Piece*);
int remove_piece_association(Position*, Piece*);
int add_association(Piece* piece, Position* pos, ASSOCIATION_STATE state);
int remove_position_link(Board* board, Piece* piece);

int place_piece(Board*, Piece*, int x, int y);
int remove_piece(Board*, Piece*);



#endif