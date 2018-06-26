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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) return {};
        int i = 0;
        int j = 0;
        int dir = 0;
        int k = 0;
        vector<int> res;
        vector<vector<bool>> v(matrix.size(), vector<bool>(matrix[0].size(), 0));
        while(k < matrix.size() * matrix[0].size()){
        // for(int k = 0; k < matrix.size() * matrix[0].size(); k++){
            // res.push_back(matrix[i][j]);
            if (dir % 4 == 0){
                if (j < matrix[0].size() - 1 && !v[i][j]){ v[i][j] = true; res.push_back(matrix[i][j]); j++; k++;}
                else dir++;
            }
            if( dir % 4 == 1){
                if (i < matrix.size() - 1 && !v[i][j]) {v[i][j] = true; res.push_back(matrix[i][j]); i++; k++;}
                else dir++;
            }
            if (dir % 4 == 2){
                if(j >0 && !v[i][j]) {v[i][j] = true; res.push_back(matrix[i][j]); j--; k++;}
                else dir++;
            }
            if (dir %4 == 3){
                if (i > 0 && !v[i][j]) {v[i][j]=true; res.push_back(matrix[i][j]); i--; k++;}
                else dir++;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> v = {{1,2,3,4}, {5,6,7,8}, {9, 10, 11, 12}, {13,14,15,16}};
    auto res = s.spiralOrder(v);
    for(auto &i: res) cout << i << ",";
    cout << endl;
    return 0;
}

