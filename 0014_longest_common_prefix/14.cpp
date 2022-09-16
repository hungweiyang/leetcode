#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
 *
 */

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        for (string s : strs) {
            int i;
            for (i = 0; i < s.size() && i < prefix.size(); ++i) {
                if (s[i] != prefix[i])
                    break;
            }
            prefix.erase(i, string::npos);
        }
        return prefix;
    }
};

int main()
{
    Solution s;
    vector<string> q = {"flower", "flow", "fl"};
    cout << s.longestCommonPrefix(q) << std::endl;
    return 0;
}