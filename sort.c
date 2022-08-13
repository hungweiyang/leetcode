#include <stdio.h>

void swap(int *a, int *b) {
  *a = *a ^ *b;
  *b = *a ^ *b;
  *a = *a ^ *b;
}

void bubblesort(int *nums, int len) {
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len - i - 1; j++) {
      if (nums[j] > nums[j + 1])
        swap(&nums[j], &nums[j + 1]);
    }
  }
}

void bubblesort2(int *nums, int len) {
  for (int i = 0; i < len; i++) {
    for (int j = len - 1; j > i; j--) {
      if (nums[j] < nums[j - 1])
        swap(&nums[j], &nums[j - 1]);
    }
  }
}

void bubblesort3(int *nums, int len) {
  for (int i = 0; i < len; i++) {
    for (int j = i; j < len; j++) {
      if (nums[i] > nums[j])
        swap(&nums[i], &nums[j]);
    }
  }
}

int main() {
  int nums[] = {5, 4, 3, 2, 1};
  int len = sizeof(nums) / sizeof(int);

  for (int i = 0; i < len; i++)
    printf("%d, ", nums[i]);
  printf("\n");

  bubblesort3(nums, len);

  for (int i = 0; i < len; i++)
    printf("%d, ", nums[i]);
  printf("\n");

  return 0;
}