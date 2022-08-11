#include <stdio.h>
#include <string.h>

#define max(m, n) ((m) > (n)) ? (m) : (n)

void checkPalindrome(int l, int r, char *s, int *start, int *maxlen) {
  int len = strlen(s);
  while (l >= 0 && r < len && s[l] == s[r]) {
    --l;
    ++r;
  }

  ++l;
  --r;
  if (*maxlen < (r - l + 1)) {
    *maxlen = r - l + 1;
    *start = l;
  }
}

char *longestPalindrome(char *s) {
  int len = strlen(s);
  int maxlen = 0;
  int start = 0;
  int tmp1, tmp2;
  for (int i = 0; i < len; i++) {
    checkPalindrome(i, i, s, &start, &maxlen);
    checkPalindrome(i, i + 1, s, &start, &maxlen);
  }

  s[start + maxlen] = 0;
  return &s[start];
}

int main() {
  char s[] = "";
  printf("%s\n", longestPalindrome(s));
}