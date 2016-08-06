
#include <unordered_map>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
    vector<string> split(const string &s, char delim = ' ') {
        stringstream ss(s);
        vector<string> elems;
        string item;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }
public:
    bool wordPattern(string pattern, string str) {
        vector<string> words = split(str);
        //for(const auto &w : words)
        //    cout << w << "\n";
        if(pattern.size() != words.size()) return false;

        unordered_map<string, char> map1;
        unordered_map<char, string> map2;
        for(unsigned i =0; i < pattern.size(); i++){
            const char c = pattern[i];
            const string word = words[i];
            if(map1.find(word) == map1.end() && map2.find(c) == map2.end()){
                map1[word] = c;
                map2[c] = word;
            }else if(map1.find(word) != map1.end() && map2.find(c) != map2.end()){
                if(map1[word] == c && map2[c] == word) continue;
                else return false;
            }else{
                return false;
            }
        }

        return true;
    }
};


int main(){
    Solution s;
    cout << s.wordPattern("abba", "cat dog dog cat") <<"\n";
    cout << s.wordPattern("abbb", "cat dog dog dog") <<"\n";
    cout << s.wordPattern("ab", "cat dog dog dog") <<"\n";
    cout << s.wordPattern("ab", "dog cat") <<"\n";

}
