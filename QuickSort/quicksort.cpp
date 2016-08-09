#include <vector>
#include <iostream>
#include <algorithm>

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

void quicksort(int *a, int low, int high){
	if(low<high){
		int p = partition(a, low, high);
		quicksort(a,low, p);
		quicksort(a, p+1, high);
	}
}

int
main ()
{

  vector<int> a{7, 16, 3, 5, 1, 11, 2, 45, 24, 0, -1, 11, 11};
  //int s = mergesort (a, 10);
  //ipartition(a, 0, 7);
  quicksort(a.data(), 0, a.size());
  for (int i = 0; i <a.size(); ++i)
    cout << a[i] << " ";
  cout << "\n";
  return 0;
}
