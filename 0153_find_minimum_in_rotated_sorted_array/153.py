from typing import List

class Solution:
    def process(self, nums: List[int], S: int) -> int:
        left, right = 0, 1
        min_len = 999
        sum = nums[left]
        while right <= len(nums):
            if sum >= S:
                min_len = min(min_len, right - left)
                sum -= nums[left]
                left += 1
                right = max(left+1, right)
            else:
                sum += nums[right]
                right += 1

        return min_len



print(Solution().process([3, 4, 1, 1, 6], 7))