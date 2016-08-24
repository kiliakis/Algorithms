#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <cassert>
#include <random>


using namespace std;

int partition(int *a, int low, int high){
	int pivot = a[high-1];
	int i = low;
	for(int j = low; j < high-1; ++j){
		if(a[j]<=pivot){
			swap(a[j], a[i]);
			i++;
		}
	}
	swap(a[i], a[high-1]);
	return i;

}


int partition2(int *a, int low, int high)
{
    int mid = (low+high)/2;
    swap(a[high-1], a[mid]);
	int pivot = a[high-1];
    int i = low;
	int j = high-2;
    while(i <=j ){
        while(a[i] < pivot) i++;
        while(a[j] > pivot) j--;
        if(i<=j){
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    swap(a[high-1], a[i]);
    return i;
}



int partition(int *a, int low, int high, int pivI)
{
	int pivot = a[pivI];
    swap(a[pivI], a[low]);
	int i = low+1;
	int j = high-1;
    while(i <=j ){
        while(i <= j && a[i] <= pivot) i++;
        while(i <= j && a[j] > pivot) j--;
        if(i<j){
            swap(a[i], a[j]);
            //i++;
            //j--;
        }
    }
    assert(i-1==j);
    swap(a[low], a[j]);
    return j;
}

void quicksort(int *a, int low, int high){
	if(low<high){
		//int p = partition2(a, low, high);
		int p = partition(a, low, high, low);
		quicksort(a,low, p);
		quicksort(a, p+1, high);
	}
}

struct node{
    int x;
    int y;
    bool operator<(const node &b) const {
        if(x == b.x) return y < b.y;
        else return x<b.x;
    }
    bool operator>(const node &b) const {
        if(x == b.x) return y > b.y;
        else return y>b.y;
    }
};


int
main ()
{

  //vector<int> a{7,9,11, 10, 0,11, 0, 12, 16, 3, 5, 1,11,11, 11, 2, 45, 24, 0, -1, 0, 7, 11};
  //vector<int> a{3,0,2,1,5,4};
  //sort(a.begin(), a.end());
    vector<int> a;
    for(int i = 0; i < 100; ++i){
        a.push_back(rand()%100);
    }

    for (int i = 0; i <a.size(); ++i)
        cout << a[i] << " ";
    cout << "\n";

  vector<node> b{{1,-1}, {3,2}, {2, -1}, {2,-4}};
  
  //auto comp = [](const node &a, const node &b){return a.x > b.x;};
  //sort(b.begin(), b.end(), greater<node>());
  //sort(a.begin(), a.end(), greater<int>());
  //for(auto x: b){
  //  cout << x.x << ", " << x.y << "\n";
  //}
  //int s = mergesort (a, 10);
  //cout << partition(a.data(), 0, a.size(), 4) << "\n";
  quicksort(a.data(), 0, a.size());
  for (int i = 0; i <a.size(); ++i)
    cout << a[i] << " ";
  cout << "\n";
  return 0;
}
