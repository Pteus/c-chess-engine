#include "defs.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  AllInit();

  for (int index = 0; index < BRD_SRQ_NUM; ++index) {
    if (index % 10 == 0) {
      printf("\n");
    }

    printf("%5d", Sqr120ToSqr64[index]);
  }

  printf("\n");
  printf("\n");

  for (int index = 0; index < 64; ++index) {
    if (index % 8 == 0) {
      printf("\n");
    }

    printf("%5d", Sqr64ToSqr120[index]);
  }

  return EXIT_SUCCESS;
}