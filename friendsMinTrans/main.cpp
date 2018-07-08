#include <unordered_set>
#include <vector>
#include <bitset>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <numeric>
using namespace std;

class Solution {
public:

    vector<vector<int>> solve(vector<vector<int>> & a) {
        vector<vector<int>> res;
        vector<pair<int,int>> plus;
        vector<pair<int,int>> minus;
        for(int i =0; i < a.size(); i++){
            int sum = accumulate(a[i].begin(), a[i].end(), 0);
            if(sum < 0) minus.push_back({-sum, i});
            if(sum > 0) plus.push_back({sum, i});
        }
        function<bool(const pair<int,int>, const pair<int,int>)> comp = [](const pair<int,int> &a, const pair<int,int> &b){
            return a.first < b.first;
        };
        make_heap(plus.begin(), plus.end(), comp);
        make_heap(minus.begin(), minus.end(), comp);
        while(plus.size() && minus.size()){
            auto p = plus.front();
            auto m = minus.front();
            pop_heap(plus.begin(), plus.end()); plus.pop_back();
            pop_heap(minus.begin(), minus.end()); minus.pop_back();
            res.push_back({p.second, min(p.first, m.first), m.second});
            if(p.first < m.first){
                m.first = m.first - p.first;
                minus.push_back(m); push_heap(minus.begin(), minus.end());
            }else if(p > m){
                p.first = p.first  - m.first;
                plus.push_back(p); push_heap(plus.begin(), plus.end());
            }
        }

        return res;
    }

};


int main() {
    Solution s;
    vector<vector<int>> v { {0, 1, -2, 5}, {-1 ,0, 3, -2}, {2, -3 , 0, -3}, {0, 0, 0, 0}};
    auto res = s.solve(v);
    for(auto &i: res) cout << i[0] << "->" << i[1] << "->" <<i[2] << "\n";
}
