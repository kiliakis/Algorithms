#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<int, bool> dp;
    string s;
    string p;
    int J;
    int I;
    bool isMatch(const string &st, const string &pa){
        dp.clear();
        s = st;
        p = pa;
        J = pa.size();
        I = st.size();
        return isMatchHelp(0, 0);
    }
    
    bool isMatchHelp(const int i, const int j){

        // First the terminating conditions
        int state = i * J + j;

        if(dp.find(state) != dp.end()) return dp[state];

        // 1) if both empty, we accept
        if(i==I && j==J) {
            dp[state] = true;
            return true;
        }
        // 2) if s is empty and p is not, then p[0] must be * only
        if(i==I && j != J && p[j] == '*'){
            bool res = isMatchHelp(i, j+1);
            dp[state] = res;
            return res;
        // 3) string is empty and pattern is not so fail 
        }else if(i==I && j != J){
            dp[state] = false;
            return false;
        }
        // if p is empty but s is not fully mathced yet, then we reject
        if(j==J && i<I){
            dp[state] = false;
            return false;
        }
        
        // Now the recursion call
        bool res = false;
        if(p[j] == s[i] || p[j] == '?'){ // first char matches
            res = isMatchHelp(i+1, j+1);
        }else if (p[j] == '*'){ // first char is *
            // either we match * with the empty seq or we match it with a char
            res = isMatchHelp(i+1, j) | isMatchHelp(i, j+1);
        }else{ // no match no * no ? so fail
            res = false;
        }

        dp[state] = res;
        return res;
    }
};


int main(){
    Solution s;
    cout << s.isMatch("aa", "a") << "\n"; //false
    cout << s.isMatch("a", "*") << "\n"; //true
    cout << s.isMatch("cb", "?a") << "\n"; //false
    cout << s.isMatch("adceb", "*a*b") << "\n"; //true
    cout << s.isMatch("acdcb", "a*c?b") << "\n"; //false
    return 0;
}

