#include<cstdio>
#include<vector>
#include<iostream>
#include<fstream>
#include <algorithm>
#include <map>
using namespace std;

typedef vector<vector<int>> vector_2d;

void equalize(int e,const vector<int> &q, int ii, int jj, vector_2d &v){
   for(int i = ii; i < ii + q[0]; ++i){
      for (int j = jj; j< jj+ q[1]; ++j)
         v[i][j] = e;
   }
}

int median(vector_2d v, int ii, int jj,const vector<int> &q){
   vector<int> temp(q[0]*q[1]);
   int k = 0;
   for(int i =ii; i < ii+q[0]; ++i)
      for(int j = jj; j < jj+q[1]; ++j)
         temp[k++] = v[i][j];

   nth_element(temp.begin(), temp.begin() + temp.size()/2, temp.end());
   //cout <<"Median is " << temp[temp.size()/2];
   return temp[temp.size()/2];
}

bool equalized(const vector_2d &v){
   const auto a = v[0][0];
   for(const auto& row: v)
      for(const auto & elem : row)
         if (elem != a) return false;
   
   return true;

}


int main(int argc, char *argv[]){
   
   int N,M,Q;
   cin >> N >> M >> Q;
   auto H = vector<vector<int>>(N, vector<int>(M));
   auto query = vector<vector<int>>(Q, vector<int>(2));
   
   for(int i = 0; i < N; ++i)
      for (int j = 0; j< M; ++j)
         cin >> H[i][j];

   for(int i = 0; i < Q; ++i)
      cin >> query[i][0] >> query[i][1];
   
//   cout << "H\n";
//   for(int i = 0; i < N; ++i){
//      for (int j = 0; j< M; ++j)
//         cout << H[i][j] << "  ";
//      cout << "\n";
//   }
   
//   cout << "query\n";
//   for(int i = 0; i < N; ++i){
//      for (int j = 0; j< 2; ++j)
//         cout << query[i][j] << "  ";
//      cout << "\n";
//   }  
   
   for(const auto& q: query){
      map<pair<int, int>, int> map;
      vector_2d A = H;
      while(!equalized(A)){
         auto max_m = 0;
         auto max_i = 0;
         auto max_j = 0;
         for(int i = 0; i+q[0]<=N; ++i){
            for(int j =0; j+q[1]<=M; ++j){
               auto it = map.find({i, j});
               if(it != map.end()) continue;
               auto m = median(A, i, j, q);
               if(m > max_m){
                  max_m = m;
                  max_i = i;
                  max_j = j;
               }
            }
         }
         equalize(max_m, q, max_i, max_j, A);
         map[{max_i, max_j}] = max_m;
      }
      cout << A[0][0] << "\n"; 
   }


   return 0;
}
