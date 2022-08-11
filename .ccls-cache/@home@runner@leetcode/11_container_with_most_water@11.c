#include <stdio.h>

#define min(m, n) ((m) < (n) ? (m) : (n))

int maxArea(int *height, int heightSize) {
  int l = 0, r = heightSize - 1;
  int maxsize = 0;

  while (r > l) {
    int lh = height[l];
    int rh = height[r];
    if (((r - l) * min(lh, rh)) > maxsize) {
      maxsize = (r - l) * min(lh, rh);
    }

    if (lh < rh)
      while (r > l && height[++l] < lh)
        ;
    else
      while (r > l && height[--r] < rh)
        ;
  }

  return maxsize;
}

int main() {
  int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};

  printf("%d\n", maxArea(height, sizeof(height) / sizeof(int)));
}