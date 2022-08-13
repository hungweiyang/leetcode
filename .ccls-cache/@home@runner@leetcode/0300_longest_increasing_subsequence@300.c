#include <stdio.h>
#include <stdlib.h>

#define max(m, n) (((m) > (n)) ? (m) : (n))

int lengthOfLIS(int *nums, int numsSize) {
  int ret = 0;
  int *len = malloc(numsSize * sizeof(int));
  for (int i = 0; i < numsSize; i++) {
    len[i] = 1;
    for (int j = 0; j < i; j++) {
      if (nums[i] > nums[j]) {
        len[i] = max(len[j] + 1, len[i]);
      }
    }
    ret = max(ret, len[i]);
  }
  free(len);
  return ret;
}

int main() {
  int nums[] = {0, 2, 0, 4, 1, 6};
  printf("%d\n", lengthOfLIS(nums, sizeof(nums) / sizeof(int)));
}