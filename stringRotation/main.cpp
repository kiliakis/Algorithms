#include <unordered_set>
#include <vector>
#include <bitset>
#include <iostream>
#include <string>

using namespace std;

bool isSubstring(string s1, string s2){
    for(int i =0; i < s1.size(); i++){
        int j = 0;
        while(j < s2.size() && i+j < s1.size() && s1[i+j] == s2[j]) j++;
        if (j ==s2.size()) return true;
        if (i+j == s1.size()) return false;
    }
    return false;
}

class Solution {
public:
    bool isRotation(string s1, string s2) {
        string s = s1 + s1.substr(0, s1.size()-1);
        cout << s << "\n";
        return s1.size() == s2.size() && isSubstring(s, s2);
    }
};


int main(){
    Solution s;
    if (s.isRotation("water", "serwa"))
        cout << "true\n";
    else  cout << "false\n";

    if (s.isRotation("water", "terwa"))
        cout << "true\n";
    else  cout << "false\n";

    if (s.isRotation("water", "erwat"))
        cout << "true\n";
    else  cout << "false\n";

    if (s.isRotation("water", "rwate"))
        cout << "true\n";
    else  cout << "false\n";

    if (s.isRotation("water", "water"))
        cout << "true\n";
    else  cout << "false\n";

}
