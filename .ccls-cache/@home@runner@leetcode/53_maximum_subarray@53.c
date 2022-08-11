#include <stdio.h>

#define max(m, n) ((m) > (n)) ? (m) : (n)

int maxSubArray(int *nums, int numsSize) {
  int mx = -10000;
  int current = 0;
  for (int i = 0; i < numsSize; i++) {
    current = max(nums[i] + current, nums[i]);
    mx = max(current, mx);
  }

  return mx;
}

int main() {
  int s[] = {-2, -1};
  printf("%d\n", maxSubArray(s, sizeof(s) / sizeof(int)));
}