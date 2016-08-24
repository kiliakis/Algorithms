#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;



class TrieNode {
public:
    char c;
    bool isWord;
    vector<TrieNode *> letters;
    // Initialize your data structure here.
    TrieNode()
    {
        isWord = false;
        letters.resize(26, NULL);   
    }
};

class Trie {
public:
    Trie()
    {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word)
    {
        TrieNode *next = root;
        for (const auto &s : word) {
            if (next->letters[s - 'a'] == NULL) {
                next->letters[s-'a'] = new TrieNode();
                next = next->letters[s-'a'];
                next->c = s;
                next->isWord = false;
            }else{
                next = next->letters[s-'a'];
            }
        }
        next->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string word)
    {
        TrieNode *next = root;
        for (const auto &s : word) {
            if (next == NULL) return false;
            next = next->letters[s - 'a'];
        }
        return next->isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix)
    {
        TrieNode *next = root;
        for (const auto &s : prefix) {
            if (next == NULL) return false;
            next = next->letters[s - 'a'];
        }
        return true;
    }

private:
    TrieNode *root;
};




int main(){
	Trie trie;
	trie.insert("a");
	cout << trie.search("a") << "\n";
	trie.insert("abcde");
	cout << trie.startsWith("abcd") << "\n";	
	cout << trie.startsWith("abde") << "\n";	

}
