#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class BirthdayOdds{
   public:
   
      int minPeople(int minOdds, int days){
         int people = 1;
         double p = 1;
         while(1.0 - p < (double)minOdds/100.0 ){
            p = p * ((double)(days - people)/days);
            people++;
         }
         
         return people;
      
      }
};

int main(int argc, char * argv[]){
   BirthdayOdds bo;
   cout << bo.minPeople(100, 365) << "\n";
   
   return 0;
}
