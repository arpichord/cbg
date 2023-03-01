# C Board Games

Some board games written in C.

*General object concepts*
  Board
  Piece
  Position
  Association
  
## Board

Resizable, keeps track of positions. Positions are allocated upon board initializing.

## Piece

Has various associations with positions based on several states; position availability as a valid move, for example.
  
## Position

Has a state, a piece (potentially). Also keeps track of pieces associated with it.

## Associations

Positions and pieces are at a structure level connected via the Association data struct. 
Associations (and positions) have flag-based states.
 
These associations and their given state will allow sussing out, quickly from memory, considerations regarding a particular position or piece.


Position <- Association -> Piece

Association.state = ASSOCIATION_STATE_STRIKE

From there, it can be quickly determined that if the Piece.player value is not that of the actor's piece, that they will be moving into a compromised position. The nuance of this functionality will vary based on the game. For exmample, in a four player game, two of the four may be on the same team.
