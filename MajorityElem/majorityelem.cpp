#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution{
	public:
	int majorityElem(const vector<int> & nums){
		unordered_map<int, int> map;
		for(const auto &v: nums){
			auto it = map.find(v);
			if(it == map.end())
				map[v] = 1;
			else
				map[v]++;
		}
		for(const auto &v: map)
			if(v.second > nums.size()/2)
				return v.first;
		return -1;
	}


};

int main(int argc, char * argv[]){
	Solution s;
	cout << s.majorityElem({14, 22, 5,5,5,5,5,5,5,1,1,1, 5, 7}) << "\n";
   	return 0;
}
