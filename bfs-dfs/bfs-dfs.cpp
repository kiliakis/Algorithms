#include<stack>
#include<queue>
#include<vector>
#include<iostream>


using namespace std;

// we will adjacensy list for the graphs

vector<int> bfs(const vector<vector<int>> G){
    vector<int> path(G.size());
    vector<bool> visited(G.size(), false);
    queue<int> q;
    q.push(0);
    path[0] = -1;

    while(q.empty() == false){
        int node = q.front();
        q.pop();

        visited[node] = true;
        cout << "Visited node : " << node << "\n";
        for(const auto& next: G[node]){
            if(!visited[next]){
                q.push(next);
                path[next] = node;
            }
        
        }
    
    }


    return path;

}


vector<int> dfs(const vector<vector<int>> G){
    vector<bool> visited(G.size(), false);

    stack<int> s;
    s.push(0);
    vector<int> path(G.size());
    path[0] = -1;

    while(!s.empty()){
        int node = s.top();
        s.pop();
        visited[node] = true;
        cout << "Visited node : " << node << "\n";
        for(const auto& next: G[node]){
            if(!visited[next]){
                s.push(next);
                path[next] = node;
            }
        }
    }
    
    return path;
}


int main(){

    vector< vector<int> > G(7);
    G[0].push_back(1);
    G[0].push_back(2);
    G[1].push_back(3);
    G[1].push_back(4);
    G[3].push_back(5);
    G[5].push_back(6);
    cout << "Starting the bfs\n"; 
    auto res = bfs(G);
    cout << "Starting the dfs\n"; 
    res = dfs(G);

    return 0;
}
