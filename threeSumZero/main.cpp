#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct node {
    int a, b, c;
    bool operator<(const node &o) const
    {
        if (a == o.a) {
            if (b == o.b) {
                return c < o.c;
            } else
                return b < o.b;
        } else
            return a < o.a;
    }
};

vector<vector<int> > threeSum(vector<int> &A)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<int> > res;
    set<node> set;
    sort(A.begin(), A.end());
    for (int i = 0; i < A.size(); i++) {
        if (A[i] > 0) break;
        int k = A.size() - 1;
        for (int j = i + 1; j < A.size() && k > j; j++) {
            if (A[i] + A[j] > 0) break;
            while (k > j && A[i] + A[j] + A[k] > 0) k--;
            if (k > j && A[i] + A[j] + A[k] == 0) {
                // if(res.empty()) //res.push_back({A[i], A[j], A[k]});
                set.insert({A[i], A[j], A[k]});
                // else{
                //     auto v = res.back();
                //     if(v[0]!=A[i] || v[1]!=A[j] || v[2]!=A[k])
                //         res.push_back({A[i], A[j], A[k]});
                // }
            }
        }
    }
    for (const auto &s : set)
        res.push_back({s.a, s.b, s.c});
    return res;
}


int main()
{
    vector< int > matrix = {1, -4, 0, 0, 5, -5, 1, 0, -2, 4, -4, 1, -1, -4, 3, 4, -1, -1, -3};
    auto res = threeSum(matrix);
    for (int i = 0; i < res.size(); i++)
        cout << res[i][0] << " " <<  res[i][1] << " " << res[i][2] << "\n";
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
