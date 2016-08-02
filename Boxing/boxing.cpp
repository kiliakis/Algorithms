#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool threeNonEmpty(vector<vector<int>> &a){
   int e = 0;
   for(const auto &v: a)
      e += v.empty();
   return e<3;
}

class Boxing{
  // struct hit{
  //    int t;
  //    int j;
  // };
   
   public:
      int maxCredit(vector<int> a, vector<int> b, vector<int> c, vector<int> d, vector<int> e){
         reverse(a.begin(), a.end());
         reverse(b.begin(), b.end());
         reverse(c.begin(), c.end());
         reverse(d.begin(), d.end());
         reverse(e.begin(), e.end());
         vector<vector<int>> judge{a,b,c,d,e};
         //auto hits = merge(judge);
         //int index[5] = {0};
         int count = 0;
         while(threeNonEmpty(judge)){
            vector<int> a;
            for(auto &j: judge)
               if(!j.empty())
                  a.push_back(j.back());
            sort(a.begin(), a.end());
            int limit;
            if(a.back() - a.front() > 1000){
               limit = a.front();
            }else{
               count++;
               limit = a.back();
            }
            for(auto &j : judge)
               while(!j.empty() && j.back() <= limit)
                  j.pop_back();
            
         }

       
         return count;
      }


};

int main(int argc, char * argv[]){
   Boxing box;
   cout << box.maxCredit({1, 2, 3, 4, 5, 6},
                         {1, 2, 3, 4, 5, 6, 7},
                         {1, 2, 3, 4, 5, 6},
                         {0, 1, 2},
                         {1, 2, 3, 4, 5, 6, 7, 8}) << "\n";
   
   cout << box.maxCredit({100, 200, 300, 1200, 6000},
                         {},
                         {900, 902, 1200, 4000, 5000, 6001},
                         {0, 2000, 6002},
                         {1, 2, 3, 4, 5, 6, 7, 8}) << "\n";
   
   cout << box.maxCredit({5000, 6500},
                         {6000},
                         {6500},
                         {6000},
                         {0, 5800, 6000}) << "\n";
   return 0;
}
