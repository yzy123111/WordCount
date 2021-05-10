#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define N 5001

int main(int argc, char **argv) {
  char str[N];
  char *charptr;
  int wordsCount = 0, charCount = 0;
  FILE *fp = fopen(argv[2], "r");
  fgets(str, N, fp);
  charptr = str;
  if (!strcmp(argv[1], "-w")) {
    while (*(charptr)++ != '\0') {
      if ((isupper(*charptr) || islower(*charptr)) &&
          (*(charptr + 1) == ',' || *(charptr + 1) == ' ' ||
           *(charptr + 1) == '\0')) {
        wordsCount++;
      }
    }
    printf("wordsCount:%d\n", wordsCount);
  } else if (!strcmp(argv[1], "-c")) {
    while (*charptr != '\0') {
      if (isupper(*charptr) || islower(*charptr))
        charCount++;
      charptr++;
    }
    printf("charsCount:%d\n", charCount);
  }

  return 0;
}