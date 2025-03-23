#include "defs.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  AllInit();
  U64 playBitBoard = 0ULL;

  for (int index = 0; index < 64; index++) {
    printf("index: %d", index);
    PrintBitBoard(SetMask[index]);
    printf("\n");
  }

  SETBIT(playBitBoard, 0);
  PrintBitBoard(playBitBoard);
  SETBIT(playBitBoard, 1);
  PrintBitBoard(playBitBoard);
  CLRBIT(playBitBoard, 1);
  PrintBitBoard(playBitBoard);

  return EXIT_SUCCESS;
}