#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;
class Solution{
public:
	int coinChange(vector<int>coins, int amount){
		vector<int> dp(amount+1, amount+1);
		dp[0] = 0;
		sort(coins.begin(), coins.end());
		for(int s =1; s <= amount; s++){
			for(const auto &c: coins)
				if(c <= s)
					dp[s] = min(dp[s-c]+1, dp[s]);
		}

		return dp[amount] < amount+1 ? dp[amount] : -1 ;
	}


};

int main(int argc, char * argv[]){
	Solution s;
	cout << s.coinChange({1,2,5}, 11) << "\n";
	cout << s.coinChange({2}, 3) << "\n";
	cout << s.coinChange({1,2,3,4,5}, 53) << "\n";
	cout << s.coinChange({4,7}, 12) << "\n";
	return 0;
}
