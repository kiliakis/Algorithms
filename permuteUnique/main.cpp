#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
    // void addAllPlaces(int a, unordered_set<vector<int>> &prev){
        // unordered_set<vector<int>> res;
        // for(auto &v: prev){
        //     v.push_back(a);
        //     res.insert(v);
        //     for(int i = v.size()-1; i >0; i--){
        //         swap(v[i], v[i-1]);
        //         res.insert(v);
        //     }
        // }
        // prev = res;
    // }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_set<vector<int>> res;
        // if(nums.empty()) return res;
        // res.insert({nums[0]});
        // for(int i =1; i < nums.size(); i++){
        //     addAllPlaces(nums[i], res);
        // }
        vector<vector<int>> r;
        // for(auto &i : res) r.push_back(i)
        return r;
    }
};

int main(){
    Solution s;
    vector<int> matrix = {-1, 2, 1, -4};

    auto res = s.permuteUnique(matrix);

    return 0;
}

