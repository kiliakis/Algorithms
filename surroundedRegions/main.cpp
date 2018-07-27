#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <string>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

void print(vector<int> v){
    for(auto &i: v) cout << i << " ";
        cout << "\n";
}

class Solution {
public:
    int rows;
    int cols;
    vector<vector<bool>> visited;

    
    void dfs(int si, int sj, vector<vector<char>> &board){
        stack<pair<int, int>> s;
        s.push({si, sj});
        while(s.size()){
            auto top = s.top(); s.pop();
            int i = top.first;
            int j = top.second;
            visited[i][j] = true;
            if(i+1 < rows && board[i+1][j] == 'O' && !visited[i+1][j]) s.push({i+1, j});
            if(j+1 < cols && board[i][j+1] == 'O' && !visited[i][j+1]) s.push({i, j+1});
            if(i-1 >= 0 && board[i-1][j] == 'O' && !visited[i-1][j]) s.push({i-1, j});
            if(j-1 >= 0 && board[i][j-1] == 'O' && !visited[i][j-1]) s.push({i, j-1});
        }
    }
    
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
        rows = board.size();
        cols = board[0].size();
        visited.resize(rows, vector<bool>(cols, false));
        for(int j = 0; j < board[0].size(); j++) {
            if(board[0][j] == 'O' && !visited[0][j]) dfs(0, j, board);
            if(board[rows-1][j] == 'O' && !visited[rows-1][j]) dfs(rows-1, j, board);
        }
        for(int i = 0; i < board.size(); i++) {
            if(board[i][0] == 'O' && !visited[i][0]) dfs(i, 0, board);
            if(board[i][cols-1] == 'O' && !visited[i][cols-1]) dfs(i, cols-1, board);
        }
        
        for(int i = 1; i < board.size()-1; i++) {
            for(int j = 1; j < board[0].size()-1; j++){
                if(board[i][j] == 'O' && !visited[i][j]) board[i][j] = 'X';
            }
        }
    
    }
};

int main(){
    Solution s;

    vector<vector<char>> grid = {{'O','O','O'}, {'O','O','O'}, {'O','O','O'}};
    s.solve(grid);

    for(auto &row: grid){
        for(auto &c: row){
            cout << c << " ";
        }
        cout << endl;
    }

    return 0;
}

