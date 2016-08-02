#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


class Cut{
public:
    int getMaximum(vector<int> lengths,int cuts){
        // first we go for multiples of 10
        int res = 0;
        for(int i =0; i < lengths.size(); ++i){
            if(lengths[i] % 10 == 0){
                const int num = lengths[i]/10 -1;
                res += num > cuts ? cuts : num+1;
                cuts -= num;
                lengths[i] = 0;
            }
            if (cuts < 1) break;
        }
        
        for(int i =0; i < lengths.size(); ++i){
            if(lengths[i] >10){
                const int num = lengths[i]/10;
                res += num > cuts ? cuts : num;
                cuts -= num;
            }
            if(cuts < 1) break;
        }
        
        return res;
    }
};

int main(int argc, char * argv[]){
        
    Cut cut;
    cout << cut.getMaximum({13, 20, 13},2) << "\n";
    cout << cut.getMaximum({5, 5, 5, 5},2) << "\n";
    cout << cut.getMaximum({34, 10, 48}, 4) << "\n";
    cout << cut.getMaximum({30, 50, 30, 50}, 350) << "\n";
    
    return 0;
}
