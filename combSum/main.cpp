#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    void unite(vector<vector<int>> &curr, vector<vector<int>> &newset){
        curr.insert(curr.end(), newset.begin(), newset.end());
    }

    vector<vector<int>> append(int num, vector<vector<int>> currset){
        for(auto &a: currset){
            a.push_back(num);
        }
        return currset;
    }

    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        sort(c.begin(), c.end());
        vector<vector<vector<int>>> dp(t+1);
        for(int i = 0; i < c.size(); i++){
            for (int j = 1; j < dp.size(); j++){
                int k = c[i];
                if (k < j){
                    auto newset = append(k, dp[j-k]);
                    unite(dp[j], newset);
                }else if (k == j){
                    dp[j].push_back({k});
                }
            }
        }

        vector<vector<int>> res(dp[t].begin(), dp[t].end());
        return res;
    }

};

int main(){
    Solution s;
    vector<int> matrix = {2, 3, 5};

    auto res = s.combinationSum(matrix, 8);
    for(auto &r : res){
        cout << "\n[ ";
        for(auto &i: r) cout << i << " ";
        cout << "]";
    }
    cout << "\n";
    return 0;
}

