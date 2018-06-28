
#include <unordered_map>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void print(const vector<int> &v){
    cout << "[";
    for(auto &a: v) cout << a << ",";
    cout << "]\n";
}

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int> nums){
        vector<int> res;
        int i = 0;
        while(i < nums.size()){
            if(nums[i] != i+1 && nums[i] != nums[nums[i]-1]){
                swap(nums[i], nums[nums[i]-1]);
            }else i++;
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]!= i+1) res.push_back(i+1);
        }
        return res;
    }

};


int main(){
    Solution s;
    auto res = s.findDisappearedNumbers({4, 3, 2, 7, 8, 2, 3, 1});
    print(res);
}
