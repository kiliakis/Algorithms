#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class PipeCuts{
   public:
   
      double probability(vector<int> loc, int L){
         const int n = loc.size();
         int perms = n * (n-1) / 2;
         int e = 0;
         for(int i = 0; i < n; ++i)
            for(int j = i+1; j < n; ++j){
               if(loc[i] < loc[j])
                  e+= (loc[i] > L) 
                      || (loc[j] - loc[i] > L) 
                      || (100 - loc[j] > L);
               else
                  e+= (loc[j] > L) 
                      || (loc[i] - loc[j] > L) 
                      || (100 - loc[i] > L);

            }


         return 1.0*e / perms;
      }
};

int main(int argc, char * argv[]){
   PipeCuts pc;
   cout << pc.probability({25, 50, 75}, 25) << "\n";
   cout << pc.probability({25, 50, 75}, 50) << "\n";
   cout << pc.probability({25, 50, 75}, 24) << "\n";
   cout << pc.probability({99, 88, 77, 66, 55, 44, 33, 22, 11}, 50) << "\n";
   return 0;
}
