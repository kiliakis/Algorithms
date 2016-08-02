// Example program
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

long long a[100][100][2];

class AvoidRoads{
    
    string stringfy(int a, int b, int c, int d){
        return to_string(a) + " " 
                + to_string(b) + " " 
                + to_string(c) + " " 
                + to_string(d);  
    }
public:
	long long numWays(int W, int H, vector<string> badS){
    	
		
		for(int i = 0; i <= H; ++i)
			for(int j = 0; j<= W; ++j)
				a[i][j][0] = 0;
		
    	a[H][W][0] = 1;
		a[H][W][1] = 0;
        int step = 1;
        for(int k = 0; k<W+H; ++k){
         	for(int i = 0; i<=H; ++i){
            	for(int j =0; j<=W; ++j){
                 	long long sum = 0;
					if(j+1<=W){
                    	auto str1 = stringfy(i, j, i, j+1);
                    	auto str2 = stringfy(i, j+1, i, j);
                    	if(find(badS.begin(), badS.end(), str1) == badS.end() 
								&& find(badS.begin(), badS.end(), str2) == badS.end())
                        	sum += a[i][j+1][1-step];
					}
					if(i+1<=H){
						auto str1 = stringfy(i, j, i+1, j);
                    	auto str2 = stringfy(i+1, j, i, j);
						if(find(badS.begin(), badS.end(), str1) == badS.end()
								&& find(badS.begin(), badS.end(), str2) == badS.end())
							sum += a[i+1][j][1-step];
					}
					a[i][j][step] = sum;
					
                } 
            }
			step = 1-step;
		}
    	
		return a[0][0][1-step];
        
    
    }

};

int main()
{
    AvoidRoads ar;
    cout << ar.numWays(6, 6,{"0 0 0 1", "6 6 5 6"}) << "\n";
    //cout << ar.numWays(1, 1,{}) << "\n";
}
