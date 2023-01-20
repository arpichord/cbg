typedef enum POSITION_TYPES{
    AVAILABLE = 1 >> 0,
    DANGER = 1 >> 1,
    BLOCKED = 1 >> 2
} POSITION_TYPE;

typedef struct {
    POSITION_TYPE position_type;
    
} Position;

typedef struct {
    


} Board;