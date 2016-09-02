#include <vector>
#include <iostream>
using namespace std;

int partition(int *a, int size){
	int pivot = a[size-1];
	int i = 0;
	for(int j = 0; j<size-1; j++){
		if(a[j]<= pivot){
			swap(a[i], a[j]);
			i++;
		}
	}
	swap(a[i], a[size-1]);
	return i;
}

void sortK(int *a, int size, int K){
	if(size <=1 || K==0) return;
	int mid = partition(a, size);
	
	if(mid<K){
		sortK(a, mid, mid);
		sortK(a+mid, size-mid, K-mid);
	}else{
		sortK(a, mid, K);
	}
	
}



int kSmall(int *a, int last, int K){
	//if(first >= last) return -100;
	int mid = partition(a, last);
	if(mid> K)
		return kSmall(a, mid, K);
	else if(mid<K)
		return kSmall(a+mid, last-mid, K-mid);
	else
		return a[mid];

}


int main(){
	vector<int> a = { 12, 7, 3,8 , 4, 1, 20, 0};
	//sortK(a.data(), a.size(), 1);
	//cout << kSmall(a.data(), 0, a.size()-1, 3) << "\n";
	//for(auto i:a) cout << i << "\n";
	for(int i = 0; i < a.size(); i ++){
		auto b = a;
		sortK(b.data(), b.size(), i);
		for(auto i:b) cout << i << "\n";
		cout << "\n";
		//cout << kSmall(b.data(),b.size(), i) << "\n";
	}	
}
