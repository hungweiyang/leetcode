from typing import List

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mydict = {}
        for i in range(len(strs)):
            k = ''.join((sorted(strs[i])))
            if k in mydict:
                mydict[k].append(strs[i])
            else:
                mydict[k] = [strs[i]]
        
        
        return mydict.values()

        
        
ans = Solution().groupAnagrams(["eat","tea","tan","ate","nat","bat"])
for i in ans:
    print(i)