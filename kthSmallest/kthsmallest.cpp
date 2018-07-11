#include <queue>
#include <iostream>

using namespace std;

class Solution{

    struct elem{
        int i;
        int j;
        int val;

        bool operator<(const elem &e2) const{
            return val > e2.val;
        }
    };

public:
    int kthsmallest(vector< vector<int> > & matrix, int k){
        
        priority_queue<elem> pq;
        pq.push({0,0, matrix[0][0]});
        k--;
        while(!pq.empty() && k>0){
            auto e = pq.top();
            pq.pop();
            if(e.i+1 < matrix.size()){
                pq.push({e.i+1, e.j, matrix[e.i+1][e.j]});
            }
            if(e.j+1 < matrix.size()){
                pq.push({e.i, e.j+1, matrix[e.i][e.j+1]});
            }
            k--;
        }
        if(pq.empty()) return -1;
        return pq.top().val;
    }

};


int main(){
    Solution s;
    vector< vector<int> > matrix = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    cout << s.kthsmallest(matrix, 8) << "\n";
    cout << s.kthsmallest(matrix, 4) << "\n";
    return 0;
}

/**
 *
 *  * Your RandomizedSet object will be instantiated and called as such:
 *
 *   * RandomizedSet obj = new RandomizedSet();
 *
 *    * bool param_1 = obj.insert(val);
 *
 *     * bool param_2 = obj.remove(val);
 *
 *      * int param_3 = obj.getRandom();
 *
 *       */
