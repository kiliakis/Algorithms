// Example program
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class FlowerGarden{
private:
    struct flower{
        int h;
        int b;
        int w;

        bool operator<(const flower &c){
            return b < c.b;
        }
    };
public:
    vector<int> getOrdering(const vector<int> &height,
                            const vector<int> &bloom,
                            const vector<int> &wilt){
        vector<flower> flowers;
        
        for(int i = 0; i < height.size(); ++i)
            flowers.push_back({height[i], bloom[i], wilt[i]});
        
        vector<flower> order;
        
        sort(flowers.begin(), flowers.end());

        int j = 0;
        for(int i = 0; i < flowers.size(); ++i){
            int day = flowers[i].b;
            while(j<flowers.size() && flowers[j].b == day){
                const auto a = &flowers[j];
                int pos = order.size();
                for(int k = order.size(); k>0; k--){
                    if(((order[k-1].b<=day && order[k-1].w>=day && a->h < order[k-1].h) 
                         || ((order[k-1].w < a->b || a->w < order[k-1].b)
                             && a->h > order[k-1].h)))
                        pos = k-1;
                    if(order[k-1].b<=day && order[k-1].w>=day && a->h > order[k-1].h){
                        pos = k;
                        break;
                    }
                }
                order.insert(order.begin()+pos, flowers[j]);
                j++;
            }
        }
        vector<int> res;
        for(const auto &f: order)
            res.push_back(f.h);
        return res;
    }

};

int main()
{
    FlowerGarden fg;
    auto res =  fg.getOrdering({5,4,3,2,1}, {1,1,1,1,1}, {365,365,365,365,365});
    for(const auto &v : res)
        cout << v << "\n";
    
    cout<< "\n";
    res =  fg.getOrdering({5,4,3,2,1}, {1,5,10,15,20}, {4,9,14,19,24});
    for(const auto &v : res)
        cout << v << "\n";
    
    cout<< "\n";
    res =  fg.getOrdering({5,4,3,2,1}, {1,5,10,15,20}, {5,10,15,20,25});
    for(const auto &v : res)
        cout << v << "\n";
    
    cout<< "\n";
    res =  fg.getOrdering({5,4,3,2,1}, {1,5,10,15,20}, {5,10,14,20,25});
    for(const auto &v : res)
        cout << v << "\n";
    
    cout<< "\n";
    res =  fg.getOrdering({1,2,3,4,5,6}, {1,3,1,3,1,3}, {2,4,2,4,2,4});
    for(const auto &v : res)
        cout << v << "\n";
    
    cout<< "\n";
    res =  fg.getOrdering({3,2,5,4}, {1,2,11,10}, {4,3,12,13});
    for(const auto &v : res)
        cout << v << "\n";
    
    return 0;
}
