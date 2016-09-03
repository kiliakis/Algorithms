#include <vector>
#include <iostream>
#include <limits.h>
#include <algorithm>
#include <map>
using namespace std;


int longestIncreasingSubs(vector<int> list){
    map<int, int, bool(*)(int, int)> map([](int a, int b){return b<a;});
    map[0] = -INT_MAX;
    for(int i = 0; i < list.size(); i++){
        for(const auto &m: map){
            if(m.second < list[i]){
                if(map.find(m.first+1) == map.end())
                    map[m.first+1] = list[i];
                else
                    map[m.first+1] = min(list[i], map[m.first+1]);
                cout << m.first+1 << " " << list[i] << "\n";
                break;
            }
        }
    }
    return (map.begin())->first;
}


int main(){
    vector<int> list = {16, 3, 5, 19, 10, 14, 12, 0, 15, 22, 16};
    cout << longestIncreasingSubs(list) << "\n";
}
