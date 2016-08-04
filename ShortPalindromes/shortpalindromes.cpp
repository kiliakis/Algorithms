#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string dp[25][26];

class ShortPalindromes{
	bool isPalindrome(const string &str){
		for(int i = 0; i < str.size()/2; ++i)
			if(str[i] != str[str.size()-i-1])
				return false;
		return true;
	}

public:
	

	string shortest(const string &base){
		for(int i = 0; i < base.size(); ++i)
			dp[i][0] = "";

		for(int i = 0; i < base.size(); ++i)
			dp[i][1] = base[i];
		
		
		for(int len = 2; len <= base.size(); len++){
			for(int s = 0; s < base.size(); s++ ){
				if( s+len <= base.size()){
					if (base[s]==base[s+len-1])
						dp[s][len] = base[s] + dp[s+1][len-2] + base[s];
					else{
						string left = base[s] + dp[s+1][len-1] + base[s];
						string right = base[s+len-1] + dp[s][len-1] +base[s+len-1];
						
						if(left.size() < right.size())
							dp[s][len] = left;
						else if(right.size() < left.size())
							dp[s][len] = right;
						else
							dp[s][len] = min(left, right);
						//dp[s][len] = min(left, right);
					}
				}
			}
		}
	
		return dp[0][base.size()];
	}

};

int main(int argc, char * argv[]){
    ShortPalindromes sp;
	cout << sp.shortest("RACE") << "\n";
	cout << sp.shortest("TOPCODER") << "\n";
	cout << sp.shortest("Q") << "\n";
	cout << sp.shortest("MADAMIMADAM") << "\n";
	cout << sp.shortest("ALRCAGOEUAOEURGCOEUOOIGFA") << "\n";
    
    return 0;
}
