#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <string>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int i = 0;
        int j = 0;
        int l = nums.size()+1;
        int sum = 0;
        while(i < nums.size()){
            // while(i < nums.size() && sum > s) sum -= nums[i++];
            while(j < nums.size() && sum < s) sum += nums[j++];
            if(sum >=s){
                l = min(j-i, l);
            }
            if (i < nums.size()) sum -= nums[i++];
        }
        if (l == nums.size()+1) return 0;
        else return l;
    }
};

int main() {
    Solution s;
    vector<int> v = {1,2,3,4,5};
    auto res = s.minSubArrayLen(11, v);
    // for(auto &i: res) cout << i << ",";
    cout << res << endl;
    return 0;
}

