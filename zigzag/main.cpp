#include <vector>
#include <iostream>
#include <limits.h>
#include <algorithm>
#include <map>
using namespace std;

int zigzag(vector<int> v){
    if(v.size()<1) return 0;
    map<int, int, bool(*)(int, int)> pos([](int a, int b) {return b<a;});
    map<int, int, bool(*)(int, int)> neg([](int a, int b) {return b<a;});
    pos[1] = neg[1] = v[0];

    for(int i = 1; i < v.size(); i++){
        auto n = v[i];
        for(auto &m: pos){
            if(n < m.second){
                if(neg.find(m.first+1)==neg.end())
                    neg[m.first+1] = n;
                else
                    neg[m.first+1] = min(neg[m.first+1], n);
                //cout << n << " " << m.first+1 << "\n";
                break;
            }

        }
        for(auto &m: neg){
            if(n > m.second){
                if(pos.find(m.first+1)==pos.end())
                    pos[m.first+1] = n;
                else
                    pos[m.first+1] = max(pos[m.first+1], n);
                //cout << n << " " << m.first+1 << "\n";
                break;
            }
        }
    }
    return max(pos.begin()->first, neg.begin()->first);

}

int main(){

    vector<int> v = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
    cout << zigzag(v) << "\n";
    cout << zigzag({ 1, 2, 3, 4, 5, 6, 7, 8, 9 }) << "\n";
    cout << zigzag({ 1, 7, 4, 9, 2, 5 }) << "\n";

}
