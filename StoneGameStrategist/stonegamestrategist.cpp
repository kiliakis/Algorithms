// Example program
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define check(var, pos) ((var) & (1<<pos))

class StoneGameStrategist{
	
public:	
	string play(const vector<int> &piles){
		int res = 0;
		vector<int> sizes(piles.size());
		
		string result;
		sizes[0] = piles[0];
		for(int i = 1; i < sizes.size(); ++i)
			sizes[i] = piles[i] - piles[i-1];
			
		for(const auto& p: piles)
			res = res ^ p;
		
		if(res == 0){
			result = string("YOU LOSE");
		}else{
			//res = 0;
			
			//for(const auto& p: sizes)
			//	res = res ^ p;

			int lpos = 10;
			while(lpos>0){
				if (check(res, lpos) != 0)
					break;
				--lpos;
			}
			//cout << "lpos = " << lpos << "\n";
			// lpos is the position of the left most ace
			int k = -1;
			int s = 1001;
			for(int i = 0; i< (int)piles.size(); ++i)
				if(check(piles[i], lpos) != 0 ){
					int dif = piles[i] - (res^piles[i]);
					if(dif < s && dif <= sizes[i]){
						s = dif;
						k = i;
					}
				}
			if(k >=0)
				result =  string("TAKE ") + to_string(s) 
					+ " STONES FROM PILE " + to_string(k);
			else
				result = "YOU LOSE";
		}
	
		return result;
	
	
	}


};


int main()
{
    StoneGameStrategist sgs;
    cout << sgs.play({6,6}) << "\n";
    cout << sgs.play({6,12}) << "\n";
    cout << sgs.play({3, 6, 6}) << "\n";
    cout << sgs.play({3, 5, 9, 11, 16}) << "\n";
    cout << sgs.play({32, 136, 251, 369, 403, 593, 624, 657, 729, 731, 769}) << "\n";
    //cout << ar.numWays(1, 1,{}) << "\n";
}
