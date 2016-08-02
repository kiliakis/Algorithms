#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <queue>

using namespace std;
const int size = 501;

int map[size][size];

void swap(int &x1, int &x2){
   if(x1 > x2){
      auto t = x1;
      x1 = x2;
      x2 = t;
   }
}


class Escape{
   
   struct state{
      int i;
      int j;
      int c;

      bool operator <(const state &b) const{
         return c < b.c;
      }
   };
   



public:
   int lowest(vector<string> harmful, vector<string> deadly){
      for(int i = 0; i < size; ++i)
         for(int j =0; j< size; ++j)
            map[i][j] = 0;


      for(const auto &s: harmful){
         stringstream s1(s);
         int x1,y1, x2, y2;
         s1 >> x1 >> y1 >> x2 >> y2;
         swap(x1,x2);
         swap(y1, y2);
         for(int i = y1; i<=y2; ++i )
            for (int j = x1; j <= x2; ++j)
               map[i][j] = 1;
      }

      for(const auto &s: deadly){
         stringstream s1(s);
         int x1,y1, x2, y2;
         s1 >> x1 >> y1 >> x2 >> y2;
         swap(x1,x2);
         swap(y1, y2);
         for(int i = y1; i<=y2; ++i )
            for (int j = x1; j <=x2; ++j)
               map[i][j] = -1;
      }
      /* 
      for(int i = 0; i < size; ++i){
         for(int j =0; j< size; ++j){
            cout << map[i][j];
         }
         cout << "\n";
      }
      */ 
      bool visited[size][size];
      for(int i = 0; i < size; ++i)
         for(int j =0; j< size; ++j)
            visited[i][j] = false;
      
      priority_queue<state> q;
      q.push({0,0,0});
      int res = -1;

      while(!q.empty()){
         auto s = q.top();
         const auto i = s.i;
         const auto j = s.j;
         const auto c = s.c;
         if(i == size-1 && j == size-1){
            res = c;
            break;
         }
         q.pop();
         visited[i][j] = true;
         if(i<size-1 && map[i+1][j]>=0 && !visited[i+1][j])
            q.push({i+1, j, c+map[i+1][j]}); 
         if(j<size-1 && map[i][j+1]>=0 && !visited[i][j+1])
            q.push({i, j+1, c+map[i][j+1]});
         if(i>0 && map[i-1][j]>=0 && !visited[i-1][j])
            q.push({i-1, j, c+map[i-1][j]});
         if(j>0 && map[i][j-1]>=0 && !visited[i][j-1])
            q.push({i, j-1, c+map[i][j-1]});
      }
      
   return res; 
   }   



};

int main(int argc, char * argv[]){
   Escape e;
   //cout << e.lowest({}, {})<< "\n";
   cout << e.lowest({"500 0 0 500"}, {"0 0 0 0"})<< "\n";
   cout << e.lowest( {"0 0 250 250","250 250 500 500"},
                     {"0 251 249 500","251 0 500 249"}) << "\n";
   
   return 0;
}
