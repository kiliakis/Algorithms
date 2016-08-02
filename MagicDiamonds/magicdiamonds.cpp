#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class MagcDiamonds{
public:
    long minimalTransfer(long n){
        if(n == 1) return 1;
        if(n == 2) return 2;
        if(n % 2 == 0) return 1;
        for(long i = 3; i <= sqrt(n); i+=2)
            if(n % i == 0) return 1;
        return 2;
    
    }


};

int main(int argc, char * argv[]){
   MagcDiamonds md;
   cout << md.minimalTransfer(2) << "\n";
   cout << md.minimalTransfer(4294967297) << "\n";
   cout << md.minimalTransfer(2147483647) << "\n";
   cout << md.minimalTransfer(1) << "\n";
   return 0;
}
