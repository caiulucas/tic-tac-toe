#include <stdio.h>

void printFile(char *filename) {
  FILE *file = fopen(filename, "r");

  while(!feof(file)) {
    char c = fgetc(file);
    printf("%c", c);
  }

  fclose(file);
}