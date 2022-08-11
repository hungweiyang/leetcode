#include <stdio.h>

#define max(m, n) (((m) > (n)) ? (m) : (n))
#define min(m, n) (((m) < (n)) ? (m) : (n))

int maxProduct(int *nums, int numsSize) {
  int mx = nums[0];
  int curr_max = nums[0];
  int curr_min = nums[0];

  for (int i = 1; i < numsSize; i++) {
    int tmax = curr_max * nums[i];
    int tmin = curr_min * nums[i];

    curr_max = max(max(nums[i], tmax), tmin);
    curr_min = min(min(nums[i], tmax), tmin);
    mx = max(mx, curr_max);
  }

  return mx;
}

int main() {
  int s[] = {-1, 0, -4};
  printf("%d\n", maxProduct(s, sizeof(s) / sizeof(int)));
}