#include <vector>
#include <iostream>
#include <limits.h>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <queue>
using namespace std;


class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<int, std::vector<int>, std::greater<int>> pq;
        pq.push(1);
        vector<int> res;
        unordered_set<int> nums;
        nums.insert(1);
        res.push_back(1);
        // int i = 1;
        int i = 1;
        while(true){
            int top = pq.top();
            pq.pop();
            if (i >= n){
                sort(res.begin(), res.end());
                if(res[n-1] <= top) return res[n-1];
            }
            if(nums.count(2 * top) == 0){
                nums.insert(2 * top);
                pq.push(2 * top);
                res.push_back(2 * top);
                i++;
            } 
            if(nums.count(3 * top) == 0){
                nums.insert(3 * top);
                pq.push(3 * top);
                res.push_back(3 * top);
                i++;
            }
            if(nums.count(5 * top) == 0){
                nums.insert(5 * top);
                pq.push(5 * top);
                res.push_back(5 * top);
                i++;
            }
        }
        // sort(res.begin(), res.end());
        // return res[n-1];
        return -1;
        
    }
};

int main(){
    Solution s;
    cout << s.nthUglyNumber(10) << "\n";
}
