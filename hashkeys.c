#include "defs.h"

// pos cannot change, but the pointer can:
// pos = some_other_board -> ok
// pos->side = something -> error

// this is not the same as  S_BOARD *const ptr
// ptr cannot change, but the value can
U64 GeneratePosKey(const S_BOARD *pos) {
  int sq = 0;
  U64 finalKey = 0;
  int piece = EMPTY;

  // loop the squares
  // set piece to whatever piece is on that square
  // it must be a piece (if and asserts)
  for (sq = 0; sq < BRD_SRQ_NUM; ++sq) {
    piece = pos->pieces[sq];
    if (piece != NO_SQ && piece != EMPTY) {
      ASSERT(piece >= wP && piece <= bK);
      finalKey ^= PieceKeys[piece][sq];
    }
  }

  if (pos->side == WHITE) {
    finalKey ^= SideKey;
  }

  if (pos->enPas != NO_SQ) {
    ASSERT(pos->enPas >= 0 && pos->enPas < BRD_SRQ_NUM);
    finalKey ^= PieceKeys[EMPTY][pos->enPas];
  }

  ASSERT(pos->castlePerm >= 0 && pos->castlePerm <= 15);
  finalKey ^= CastleKeys[pos->castlePerm];

  return finalKey;
}