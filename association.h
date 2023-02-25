#ifndef H_ASSOCIATION
#define H_ASSOCIATION

// Forward Declarations
typedef struct Piece Piece;
typedef struct Position Position;
typedef struct Board Board;


typedef enum ASSOCIATION_STATES {
    
    ASSOCIATION_STATE_VALID_MOVE    = 1 << 0,
    ASSOCIATION_STATE_STRIKE        = 1 << 1,
    ASSOCIATION_STATE_BLOCKED       = 1 << 2,
    ASSOCIATION_STATE_HOME          = 1 << 3,
    ASSOCIATION_STATE_NULL          = 1 << 4

} ASSOCIATION_STATE;
    
typedef struct Association {

    Piece* piece;
    Position* position;
    ASSOCIATION_STATE state;

} Association;

int remove_association(Association* asc);
int add_association(Piece* piece, Position* pos, ASSOCIATION_STATE state);
int remove_piece_associations(Piece* piece);

int update_associations(Board* board, Piece* piece);

int _update_position_association(Board* board, Piece* piece);
int _update_piece_associations(Board* board, Piece* piece);

#endif