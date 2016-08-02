#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <bitset>
#include <sstream>

using namespace std;

class BorelSets{
   struct comp{
      bool operator()(const std::bitset<10>& x, const std::bitset<10>& y)
      {
          for (int i = 9; i >= 0; i--) {
               if (x[i] ^ y[i]) return y[i];
         }
         return false;
      }
   };
   public:
      int howMany(int size, vector<string> subsets){
         set<bitset<10>, comp> set;
         for(auto &s: subsets){
            stringstream stream(s);
            int n;
            bitset<10> subset;
            while(stream >> n){
               subset[n-1] = 1;
            }
            set.insert(subset);
         }

         bool flag = true;
         auto newSet = set;
         while(flag){
            flag = false;
            auto tempSet = newSet;
            newSet.clear();
            for(auto s: tempSet){
               s.flip();
               //auto pair = set.insert(s);
               if(set.insert(s).second){
                  newSet.insert(s);
                  flag = true;
               }
            }
            for(const auto &s1 : tempSet)
               for(auto s2 : set){
                  s2 = s1 | s2;
                  if(set.insert(s2).second){
                     newSet.insert(s2);
                     flag = true;
                  }
               }
         }
         

         return set.size(); 
      }
   
};

int main(int argc, char * argv[]){
   BorelSets bs;
   cout << bs.howMany(4, {"1 2", ""}) << "\n";
   cout << bs.howMany(10, {"", "1", "2", "3", "4", "5","6", "7", "8", "9", "10"}) << "\n";
   cout << bs.howMany(5, {"", "1 1 2", "1 1 2 2 1 1", "", "2 1 1"}) << "\n"; 
   return 0;
}
