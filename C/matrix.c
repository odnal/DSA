#include <stdio.h>

int main() {

  int twoDarray[3][4] = {0};
  int size = sizeof(twoDarray)/sizeof(twoDarray[0][0]);
  printf("%d\n", size);

  for (int i=0; i<3; i++) {
    for (int j=0; j<4; j++) {
      if (i == 2 && j == 3) {
        twoDarray[i][j] = 1;
        printf("i:%d j:%d\n", i, j);
        printf("%d\n", twoDarray[i][j]);
      } else {
        twoDarray[i][j] = 0;
      }
    }
  }

  for (int i=0; i<3; i++) {
    for (int j=0; j<4; j++)
      printf("%d\n", twoDarray[i][j]);
  }

  return 0;
}
