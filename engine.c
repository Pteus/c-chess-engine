#include "defs.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  AllInit();
  U64 playBitBoard = 0ULL;

  printf("Start: \n\n");
  PrintBitBoard(playBitBoard);

  playBitBoard |= (1ULL << SQ64(D2));

  printf("Finish: \n\n");
  PrintBitBoard(playBitBoard);

  return EXIT_SUCCESS;
}