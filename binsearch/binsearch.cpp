#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

int binsearch2(int *a,int size, int key){
    if(size == 1) return a[0] < key ? 1 : 0;
    if(size == 0) return 0;
    int mid = size/2;
    if(a[mid] < key)
        return mid+binsearch2(a+mid, size-mid, key);
    else if(a[mid]>key)
        return binsearch2(a, mid, key);
    else
        return mid;
}


template <typename T>
int binsearch(const vector<T> &a, const T key){
   int low=0;
   int high=a.size()-1;
   while(high > low){
      T middle = (high + low) / 2;
      if(key > a[middle])
         low = middle+1;
      else if(key < a[middle])
         high = middle-1;
      else
         return middle;
   }
    if(a[low] < key) return low==a.size() ? low : low+1;
    else return low;
}

int main(int argc, char * argv[]){

   vector<int> a{1,3,5,6,10,12,25,40,100};
   cout << binsearch2(a.data(),a.size(), 5) << "\n";
   cout << binsearch2(a.data(),a.size(),  25) << "\n";
   cout << binsearch2(a.data(),a.size(),  0) << "\n";
   cout << binsearch2(a.data(), a.size(), 210) << "\n";
   cout << binsearch2(a.data(), a.size(), 50) << "\n";
   cout << binsearch2(a.data(),a.size(), 4) << "\n";
   cout << binsearch2(a.data(),a.size(), -1) << "\n";
 
   cout << "lower bound results\n";
   cout << lower_bound(a.begin(), a.end(), 5) - a.begin() << "\n";
   cout << lower_bound(a.begin(), a.end(), 25) - a.begin() << "\n";
   cout << lower_bound(a.begin(), a.end(), 0) - a.begin() << "\n";
   cout << lower_bound(a.begin(), a.end(), 210) - a.begin() << "\n";
   cout << lower_bound(a.begin(), a.end(), 50) - a.begin() << "\n";
   cout << lower_bound(a.begin(), a.end(), 4) - a.begin() << "\n";
   cout << lower_bound(a.begin(), a.end(), -1) - a.begin() << "\n";

   return 0;
}
