#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

void print(vector<int> v){
    for(auto &i: v) cout << i << " ";
        cout << "\n";
}

class Solution {
public:
    int rows;
    int cols;
    
    void bfs(int si, int sj, vector<vector<char>>& grid){
        queue<pair<int, int>> q;
        q.push({si, sj});
        while(q.size()){
            auto top = q.front(); q.pop();
            int i = top.first;
            int j = top.second;
            if(grid[i][j] == '1'){
                grid[i][j] = '0';
                if(i+1 < rows) q.push({i+1, j});
                if(i-1 >= 0) q.push({i-1, j});
                if(j+1 < cols) q.push({i, j+1});
                if(j-1 >= 0) q.push({i, j-1});
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        
        rows = grid.size();
        cols = grid[0].size();
        int c = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    bfs(i, j, grid);
                    c++;
                }
            }
        }
        return c;
        
    }
};

int main(){
    Solution s;

    vector<vector<char>> grid = {{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
    cout << s.numIslands(grid) << "\n";

    return 0;
}

