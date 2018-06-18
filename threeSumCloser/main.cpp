#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    
    int binsearch(vector<int> &nums, int L, int R, int key){
        
        while(L<=R){
            int mid = (L + R)/2;
            if (nums[mid] < key){
                L = mid+1;
            }else if(nums[mid] > key){
                R = mid-1;
            }else{
                return mid;
            }
        }
        
        return R;
    }
    
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int diff = abs(nums[0] + nums[1] + nums[2] - target);
        int closer = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < nums.size()-2; i++){
            int j = i+1;
            int k = nums.size()-1;
            while(j < k){
                int currsum = nums[i] + nums[j] + nums[k];
                int currdiff = abs(currsum - target);
                if (currdiff < diff){
                    diff = currdiff;
                    closer = currsum;
                }
                if (currsum < target){
                    j++;
                }else if(currsum > target){
                    k--;
                }else{
                    return closer;
                }
            }
        }
        return closer;
    }
};


int main(){
    Solution s;
    vector<int> matrix = {-1, 2, 1, -4};

    cout << s.threeSumClosest(matrix, 1) << "\n";
    cout << s.threeSumClosest(matrix, 10) << "\n";
    cout << s.threeSumClosest(matrix, -3) << "\n";
    cout << s.threeSumClosest(matrix, 0) << "\n";
    return 0;
}

