#include <map>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    std::map<int, int> hash;

    vector<int> twoSum(vector<int> &nums, int target)
    {
      int i;
        int numsSize = nums.size();
        for (i = 0; i < numsSize - 1; i++)
        {
            if (hash.find(target-nums[i]) == hash.end())
                hash[nums[i]] = i;
            else
              break;
        }
      return {i, hash[target-nums[i]]};
    }
};

int main()
{
  vector<int> a = {1,2,3,4,5};
  Solution s;
  vector<int> b = s.twoSum(a, 7);
  cout << b[0] << " " << b[1] << endl;
  return 0;
}