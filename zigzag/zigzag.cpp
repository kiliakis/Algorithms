
#include <vector>

using namespace std;

class ZigZag {
   public:
      
      int longestZigZag(vector<int> a){
         int start = 0;
         int i = 1;
         int max = 0;
         while((int)a.size() - 1> i){
            if((a[i] - a[i-1])*(a[i+1] - a[i]) < 0)
               ; 
            else {
               if(i - start > max) max = start - i;
               start = i;
            }
            i++;
         }
         return max;
      }


};

