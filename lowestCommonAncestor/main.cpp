#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <string>
#include <unordered_map>
using namespace std;



// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<TreeNode *> currPath, ppath, qpath;

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;

        currPath.push_back(root);

        if (root == p)
            ppath = vector<TreeNode *>(currPath.begin(), currPath.end());
        else if (root == q)
            qpath = vector<TreeNode *>(currPath.begin(), currPath.end());

        if (ppath.size() && qpath.size()) {
            int i = 0;
            for (i = 0; i < ppath.size() && i < qpath.size() && (ppath[i] == qpath[i]); i++);
            return qpath[i-1];
        }


        if (root->left) {
            auto res = lowestCommonAncestor(root->left, p, q);
            if (res) return res;
        }
        if (root->right) {
            auto res = lowestCommonAncestor(root->right, p, q);
            if (res) return res;
        }
        currPath.pop_back();

        return NULL;

    }
};

int main() {
    Solution s;
    TreeNode *root = new TreeNode(3);
    // TreeNode *temp = new TreeNode(5);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    // TreeNode *temp = new TreeNode(5);

    auto res = s.lowestCommonAncestor(root, root->left, root->left->right->right);
    cout << res->val << "\n";
    return 0;
}

