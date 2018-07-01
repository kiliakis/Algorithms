#include <unordered_set>
#include <vector>
#include <bitset>
#include <iostream>
#include <string>
#include <cmath>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<char> syms;
    int size;

    string solve(int symbols, int size) {
        int length = pow(symbols, size) + size - 1;
        this->size = size;
        string res;
        for (int i = 0; i < symbols; i++) syms.push_back('a' + i);
        for (int i = 0; i < this->size - 1; i++) {
            res.push_back('a' + i);
        }
        unordered_set<string> set;
        auto flag = solve(res, set, length);
        return res;
    }

    string solve(string &res, unordered_set<string> &set, int length) {
        if (res.size() == length) return res;
        for (auto c : syms) {
            res.push_back(c);
            auto last = res.substr(res.size() - this->size);
            if (set.count(last) == 0) {
                set.insert(last);
                if(res.size() == length) return res;
                auto ret = solve(res, set, length);
                if(ret.size() == length) return ret;
                set.erase(last);
            }
            res.pop_back();
        }
        return "";
    }

    bool validate(string &res, int symbols, int size) {
        unordered_set<string> set;
        for (int i = size; i <= res.size(); i++) {
            set.insert(res.substr(i - size, size));
        }
        return set.size() == pow(symbols, size);
    }

};


int main() {
    Solution s;

    auto res = s.solve(2, 3);
    cout << res << "\n";
    if ( s.validate(res, 2, 3)) cout << "True\n";
    else cout << "false\n";
}
