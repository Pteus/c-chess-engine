#ifndef DEFS_H
#define DEFS_H

#include <stdio.h>
#include <stdlib.h>

// comment this so that the assert logic is not ran
#define DEBUG

#ifndef DEBUG
// if not debug, assert does nothing
#define ASSERT(n)
#else
#define ASSERT(n)                                                              \
  if (!(n)) {                                                                  \
    printf("%s - Failed", #n);                                                 \
    printf(" On %s", __DATE__);                                                \
    printf(" At %s", __TIME__);                                                \
    printf(" In File %s", __FILE__);                                           \
    printf(" At Line %d\n", __LINE__);                                         \
    exit(1);                                                                   \
  }
#endif

typedef unsigned long long U64; // unsigned 64bit integer

#define NAME "engine 1.0"
#define BRD_SRQ_NUM 120 // 120 squares on the board
#define MAX_GAME_MOVES 2048
#define START_FEN "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"

enum { EMPTY, wP, wN, wB, wR, wQ, wK, bP, bN, bB, bR, bQ, bK };

enum {
  FILE_A,
  FILE_B,
  FILE_C,
  FILE_D,
  FILE_E,
  FILE_F,
  FILE_G,
  FILE_H,
  FILE_NONE
}; // columns
enum {
  RANK_1,
  RANK_2,
  RANK_3,
  RANK_4,
  RANK_5,
  RANK_6,
  RANK_7,
  RANK_8,
  RANK_NONE
}; // lines

enum { WHITE, BLACK, BOTH };

enum {
  A1 = 21,
  B1,
  C1,
  D1,
  E1,
  F1,
  G1,
  H1,
  A2 = 31,
  B2,
  C2,
  D2,
  E2,
  F2,
  G2,
  H2,
  A3 = 41,
  B3,
  C3,
  D3,
  E3,
  F3,
  G3,
  H3,
  A4 = 51,
  B4,
  C4,
  D4,
  E4,
  F4,
  G4,
  H4,
  A5 = 61,
  B5,
  C5,
  D5,
  E5,
  F5,
  G5,
  H5,
  A6 = 71,
  B6,
  C6,
  D6,
  E6,
  F6,
  G6,
  H6,
  A7 = 81,
  B7,
  C7,
  D7,
  E7,
  F7,
  G7,
  H7,
  A8 = 91,
  B8,
  C8,
  D8,
  E8,
  F8,
  G8,
  H8,
  NO_SQ,
  OFFBOARD
};

enum { FALSE, TRUE };

enum { WKCA = 1, WQCA = 2, BKCA = 4, BQCA = 8 }; // castling

typedef struct {
  int move;
  int castlePerm;
  int enPas;
  int fiftyMove;
  U64 posKey;
} S_UNDO;

typedef struct {
  int pieces[BRD_SRQ_NUM];
  U64 pawns[3];

  int KingSq[2];

  int side;
  int enPas;
  int fiftyMove;

  int ply;
  int hisPly;

  int castlePerm;

  U64 posKey;

  int pceNum[13];
  int bigPce[2]; // not pawns
  int majPce[2]; // rooks and queens
  int minPce[2]; // bishops and knights
  int material[2];

  S_UNDO history[MAX_GAME_MOVES];

  // piece list
  int pList[13][10];

} S_BOARD;

/* MACROS */
// return the equivalent square of the file and rank. 120 based index
// A1 = (21 + 0) * (0 * 10) = 21
// A2 = (21 + 0) * (1 * 10) = 31
#define FR2SQ(f, r) ((21 + (f)) + ((r) * 10))
#define SQ64(sq120) Sqr120ToSqr64[sq120]
#define SQ120(sq64) Sqr64ToSqr120[sq64]
#define POP(b) PopBit(b)
#define CNT(b) CountBits(b)
#define CLRBIT(bb, sq) ((bb) &= ClearMask[(sq)])
#define SETBIT(bb, sq) ((bb) |= SetMask[(sq)])

/* GLOBALS */
extern int Sqr120ToSqr64[120];
extern int Sqr64ToSqr120[64];
extern U64 SetMask[64];
extern U64 ClearMask[64];
extern U64 PieceKeys[13][120];
extern U64 SideKey;
extern U64 CastleKeys[16];
extern char PceChar[];
extern char SideChar[];
extern char RankChar[];
extern char FileChar[];

extern int PieceBig[13];
extern int PieceMaj[13];
extern int PieceMin[13];
extern int PieceVal[13];
extern int PieceCol[13];

extern int FilesBrd[BRD_SRQ_NUM];
extern int RanksBrd[BRD_SRQ_NUM];

/* FUNCTIONS*/
// init.c
extern void AllInit();

// bitboards.c
extern void PrintBitBoard(U64 bb);
extern int PopBit(U64 *bb);
extern int CountBits(U64 b);

// hashkeys.c
extern U64 GeneratePosKey(const S_BOARD *pos);

// board.c
extern void ResetBoards(S_BOARD *pos);
extern int ParseFen(char *fen, S_BOARD *pos);
extern void PrintBoard(const S_BOARD *pos);
extern void UpdateListsMaterial(S_BOARD *pos);

#endif