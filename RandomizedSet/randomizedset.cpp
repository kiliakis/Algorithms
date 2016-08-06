#include <random>
#include <unordered_set>
#include <iostream>

using namespace std;

class RandomizedSet {

    unordered_set<int> set;
    default_random_engine generator;
    uniform_int_distribution<int> distr;

public:

	/** Initialize your data structure here. */

	RandomizedSet() {
	}



	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */

	bool insert(int val) {
        auto ret = set.insert(val);
	    return ret.second;
    }



	/** Removes a value from the set. Returns true if the set contained the specified element. */

	bool remove(int val) {
        return set.erase(val) == 1;
	}



	/** Get a random element from the set. */

	int getRandom() {
        if(set.empty()) return -1;
        auto it = set.begin();
        advance(it, distr(generator)%set.size());
	    return *it;
    }

};


int main(){
    RandomizedSet rs; //= RandomizedSet();
    cout <<  rs.insert(1) << "\n";
    cout << rs.remove(2) << "\n";
    cout << rs.insert(2) << "\n";
    cout << rs.getRandom() << "\n";
    cout << rs.remove(1) << "\n";
    cout << rs.insert(2) << "\n";
    cout << rs.getRandom() << "\n";

    return 0;
}

/**
 *
 *  * Your RandomizedSet object will be instantiated and called as such:
 *
 *   * RandomizedSet obj = new RandomizedSet();
 *
 *    * bool param_1 = obj.insert(val);
 *
 *     * bool param_2 = obj.remove(val);
 *
 *      * int param_3 = obj.getRandom();
 *
 *       */
