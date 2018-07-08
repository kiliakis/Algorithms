#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <string>
#include <unordered_map>
using namespace std;

void print(vector<int> v){
    for(auto &i: v) cout << i << " ";
        cout << "\n";
}

class Solution {
public:
    int partition2(vector<int>& nums, int l, int r){
        int pivot = nums[r];
        int id = r;
        r--;
        while(l < r){
            while(l < r && nums[l] <= pivot) l++; 
            while(l < r && nums[r] > pivot) r--;
            if(l < r){
                swap(nums[l], nums[r]);
            }
        }
        swap(nums[l], nums[id]);
        return l;
    }

    int partition (vector<int>& arr, int low, int high){
        int pivot = arr[high];    // pivot
        int i = (low - 1);  // Index of smaller element
     
        for (int j = low; j <= high- 1; j++)
        {
            // If current element is smaller than or
            // equal to pivot
            if (arr[j] <= pivot)
            {
                i++;    // increment index of smaller element
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return (i + 1);
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        // this is the place it needs to be
        k = nums.size() - k;
        int l = 0;
        int r = nums.size() -1;
        while(l < r){
            int id = partition(nums, l, r);
            print(nums);
            if(id == k) return nums[id];
            else if(id < k){
                l = id+1;
            }else{
                r = id-1;
            }
        }
        return nums[l];
        
    }
};

int main(){
    Solution s;
    vector<int> v = {1};

    v = {3,2,3,1,2,4,5,5,6};
    cout << s.findKthLargest(v, 4) << "\n";

    v = {1};
    cout << s.findKthLargest(v, 1) << "\n";
    v = {3, 2, 1, 5, 6, 4};
    cout << s.findKthLargest(v, 2) << "\n";
    

    v = {2, 1};
    cout << s.findKthLargest(v, 1) << "\n";


    return 0;
}

