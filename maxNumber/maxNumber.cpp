#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

vector<int> v1, v2;

struct state {
	long unsigned i1;
	long unsigned i2;
	int num;
	int k;
	bool operator<(const state &o) const{
		return num<o.num;
	}
};

int max(int a1, int a2, int a3, int a4){
	int a = max(a1, a2);
	int b = max(a3, a4);
	return max(a,b);
}

int solve(state s){
	if(s.k == 0) return s.num;
	int max1, max2, max3, max4;
	max1 = max2 = max3 = max4 = -1;
	if(s.i1<v1.size()){
		max1 = solve({s.i1+1, s.i2, s.num*10 + v1[s.i1], s.k-1});
		max3 = solve({s.i1+1, s.i2, s.num, s.k});
	}
	if(s.i2<v2.size()){
		max2 = solve({s.i1, s.i2+1, s.num*10 + v2[s.i2], s.k-1});
		max4 = solve({s.i1, s.i2+1, s.num, s.k});
	}
	return max(max1, max2, max3, max4);
}

vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k){
	v1 = nums1;
	v2 = nums2;
	state s1 = {0, 0, 0, k};
	int max = solve(s1);
	cout << max << "\n";
	vector<int> res;
	while(max !=0){
		res.push_back(max %10);
		max /=10;
	}
	reverse(res.begin(), res.end());
	return res;
}

int main(int argc, char * argv[]){
	vector<int> a = {1,2,3};
	vector<int> b ={3,0,0};
	maxNumber(a, b, 3);

	a = {3,4,6,5};
	b = {9,1,2,5,8,3};
	maxNumber(a, b, 5);
    
	a = {6,7};
	b = {6,0,4};
	maxNumber(a, b, 5);
	
	a = {3,9};
	b = {8,9};
	maxNumber(a, b, 3);
	
	return 0;
}
