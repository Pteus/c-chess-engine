#include "defs.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  AllInit();

  int PieceOne = rand();
  int PieceTwo = rand();
  int PieceThree = rand();
  int PieceFour = rand();

  printf("PieceOne:%X\n", PieceOne);
  printf("PieceTwo:%X\n", PieceTwo);
  printf("PieceThree:%X\n", PieceThree);
  printf("PieceFour:%X\n", PieceFour);

  int Key = PieceOne ^ PieceTwo ^ PieceThree ^ PieceFour; // xor
  printf("key: %X", Key);

  return EXIT_SUCCESS;
}