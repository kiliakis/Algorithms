#include <unordered_set>
#include <vector>
#include <bitset>
#include <iostream>

using namespace std;

class Solution {
    unordered_set< long unsigned > check;
    vector< bitset<9> > res;
    
    void solve(int n, int k, bitset<9> set){
        if(check.find(set.to_ulong()) != check.end()) return;
        if(k == 0 && n == 0) res.push_back(set);
        for(int i =0; i <9; i++){
            if(set[i] || n-i-1<0) continue;
            auto newSet = set;
            newSet[i] = 1;
            solve(n-i-1, k-1, newSet);
        }
        check.insert(set.to_ulong());
    }
    
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        solve(n, k, 0);
        vector<vector<int>> ret;
        for(const auto &set: res){
            vector<int> v;
            for(int i =0; i < 9; i++)
                if(set[i]) v.push_back(i+1);
            ret.push_back(v);
        }
        return ret;
    }
};


int main(){
    Solution s;
    auto res = s.combinationSum3(2,7);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j< res[i].size(); j++)
            cout << res[i][j] << " ";
    cout << "\n";
    }
}
