#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <string>
#include <unordered_map>
using namespace std;

class Trie {
public:
    /** Initialize your data structure here. */
    unordered_map<char, Trie *> child;
    bool isWord;
    Trie() {
        isWord = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        auto curr = this;
        for(auto c: word){
            if(curr->child.count(c) == 0){
                curr->child[c] = new Trie();
            }
            curr = curr->child[c];
        }
        curr->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    int search(string word) {
        auto curr = this;
        int i = 0;
        for(auto c: word){
            if(curr->child.count(c) > 0){
                curr = curr->child[c];
                i++;
            }else return 0;
            if(curr->isWord) return i;
        }
        return 0;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto curr = this;
        for(auto c: prefix){
            if(curr->child.count(c) > 0){
                curr = curr->child[c];
            }else return false;
        }
        return true;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        Trie *trie = new Trie();
        for(auto w: dict) trie->insert(w);
        string res;
        int i = 0;
        while(i < sentence.size()){
            auto j = sentence.find(" ", i);
            auto word = sentence.substr(i, j-i);
            int len = trie->search(word);
            if (len > 0){
                res += word.substr(0, len) + " ";
            }else{
                res += word + " ";
            }
            if(j == string::npos) i = sentence.size();
            else i = j+1;
        }
        if (res.size())
            res.pop_back();
        return res;
        
    }
};


int main() {
    Solution s;
    vector<string> dict = {"cat", "rat", "bat"};

    auto res = s.replaceWords(dict, "the cattle was rattled by the battery");
    cout << res << "\n";
    return 0;
}

