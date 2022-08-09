#include <stdio.h>
#include <string.h>

#define max(m, n) ((m) > (n)) ? (m) : (n) 

int checkPalindrome(char * s, int start, int len)
{
  if (len == 1) return 1;

  for (int i = start; i < start + len/2; i++) {
    if (s[i] != s[start + len - i])
      return 1;
  }
  return 0;
}

char * longestPalindrome(char * s)
{
  int l, r, size = 0, start = 0;
  int len = strlen(s);
  for (int i = 0; i < len-1; i++) {
    for (int j = i+1; j < len; j++) {
      if (checkPalindrome(s, i, j-i+1) == 0)
        if (j-i+1 > size) {
          size = j-i+1;
          start = i;
        }
    }
  }

  if (size == 0) size = 1;
  s[start+size] = 0;
  return &s[start];
}

int main()
{
  char s[] = "ac";
  printf("%s\n", longestPalindrome(s));
}