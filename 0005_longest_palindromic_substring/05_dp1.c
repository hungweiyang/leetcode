#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *longestPalindrome(char *s) {
  int len = strlen(s);
  int **tbl = (int **)malloc(len * sizeof(int *));
  for (int i = 0; i < len; i++)
    tbl[i] = (int *)malloc(len * sizeof(int));

  for (int i = 0; i < len; i++)
    for (int j = 0; j < len; j++)
      tbl[i][j] = 0;

  int size = 1;
  int start = 0;
  for (int i = 0; i < len; i++) {
    tbl[i][i] = 1;
  }

  for (int i = 0; i < len - 1; i++) {
    if (s[i] == s[i + 1]) {
      tbl[i][i + 1] = 1;
      size = 2;
      start = i;
    }
  }

  for (int i = 2; i < len; i++) {
    for (int j = 0; j < len - i; j++) {
      if (s[j] == s[j + i] && tbl[j + 1][j + i - 1]) {
        tbl[j][j + i] = 1;
        size = len;
        start = j;
      }
    }
  }

  for (int i = 0; i < len; i++)
    free(tbl[i]);
  free(tbl);

  s[start + size] = 0;
  return &s[start];
}

int main() {
  char s[] = "babad";
  printf("%s\n", longestPalindrome(s));
}
