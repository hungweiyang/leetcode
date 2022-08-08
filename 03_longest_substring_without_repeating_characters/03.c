#include <stdio.h>
#include <string.h>

#define max(m, n) ((m) > (n)) ? (m) : (n)

int lengthOfLongestSubstring(char * s){
  int r, l, mx;
  int len = strlen(s);
  int p[128] = {0};
  for (l = 0, r = 0, mx = 0; r < len; r++) {
    l = max(p[s[r]], l);
    mx = max(r-l+1, mx);
    p[s[r]] = r+1;
  }

  return mx;
}

int main()
{
  char s[] = "abbac";
  printf("%d\n", lengthOfLongestSubstring(s));
  
}