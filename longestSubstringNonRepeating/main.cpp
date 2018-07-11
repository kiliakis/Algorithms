#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int i = 0;
        size_t longest = 0;
        int k = 0;
        while(i < s.size()){
            int j = i;
            while(j < s.size() && set.insert(s[j]).second) j++;
            longest = max(longest, set.size());
            if (j < s.size()){
                while(k < j && s[k] != s[j]) set.erase(s[k++]);
                set.erase(s[k++]);
            }
            i = j;
        }
        return longest;
    }
};

int main(){
    Solution s;
    auto res = s.lengthOfLongestSubstring("bpfbhmipx");
    cout << res << "\n";
    return 0;
}

