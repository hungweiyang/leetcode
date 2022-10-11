#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.empty())
            return {};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res{intervals[0]};
        for (auto i : intervals)
        {
            if (res.back()[1] < i[0])
            {
                res.push_back(i);
            }
            else
            {
                res.back()[1] = max(i[1], res.back()[1]);
            }
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> problem{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    Solution s;
    for (auto i : s.merge(problem))
    {
        printf("[%d, %d]\n", i[0], i[1]);
    }
}