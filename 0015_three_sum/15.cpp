#include <iostream>
#include <vector>
#include <map>

using namespace std;

// class Solution {
// public:
//     vector<int>twoSum(int x, vector<int>& nums) {
//         std::map<int, int>hash;
//         for (auto i = nums.begin(); i != nums.end(); i++) {
//             if (hash.find(x - *i))
//             {
//                 return {-x, *i, x - *i};
//             }
//             hash[*i] = 1;
//         }
//     }
    
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>> res;
//         int len = nums.size();
//         for (int i = 0; i < len; i++) {
//             vector<int> tmp = nums;
            
//             vector<int> v = twoSum(*i, nums.erase(i));
//             if (v.size()) 
//                 res.push_back(v);
//         }
//     }
// };

int main()
{
    vector<int>q = {1,2,3};
    // Solution s;
    // vector<vector<int>> res = s.threeSum(q);
    // for (auto i = res.begin(); i != res.end(); i++) {
    //     printf("[");
    //     for (auto j = (*i).begin(); j != (*i).end(); j++) {
    //         printf("%d,", *j);
    //     }
    //     printf("],");
    // }
}