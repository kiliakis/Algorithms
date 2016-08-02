#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

template <typename T>
int binsearch(const vector<T> &a, const T key){
   int res = -1;
   int low=0;
   int high=a.size();
   while(high > low){
      T middle = (high + low) / 2;
      if(key > a[middle])
         low = middle;
      else if(key < a[middle])
         high = middle;
      else{
         res = middle;
         break;
      }
   }

   return res;

}

int main(int argc, char * argv[]){

   vector<int> a{1,3,5,6,10,12,25,40,100};
   cout << binsearch(a, 5) << "\n";
   cout << binsearch(a, 25) << "\n";
   cout << binsearch(a, 0) << "\n";
   a.push_back(200);
   cout << binsearch(a, 200) << "\n";
   cout << binsearch(a, 3) << "\n";
 
   cout << "lower bound results\n";
   cout << lower_bound(a.begin(), a.end(), 5) - a.begin() << "\n";
   cout << lower_bound(a.begin(), a.end(), 25) - a.begin() << "\n";
   cout << lower_bound(a.begin(), a.end(), 0) - a.begin() << "\n";
   cout << lower_bound(a.begin(), a.end(), 200) - a.begin() << "\n";
   cout << lower_bound(a.begin(), a.end(), 3) - a.begin() << "\n";

   return 0;
}
