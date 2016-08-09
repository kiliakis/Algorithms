#include <vector>
#include <iostream>

using namespace std;

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<int> findPath(TreeNode * root, TreeNode *p, vector<int> path){
        if(p == root) return path;
        if(root == NULL) return vector<int>();
        path.push_back(-1);
        vector<int> left = findPath(root->left, p, path);
        path.pop_back();
        path.push_back(1);
        vector<int> right = findPath(root->right, p, path);
        if(left.empty()) return right;
        if(right.empty()) return left;
        return vector<int>();
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<int> pathP, pathQ;
        pathP = findPath(root, p, vector<int>());
        pathQ = findPath(root, q, vector<int>());
        int i = 0;
        int size = min(pathP.size(), pathQ.size());
        TreeNode * node = root;
        while(i < size && pathP[i] == pathQ[i]){
            if(pathP[i] == -1)
                node = node->left;
            else
                node = node->right;
            i++;
        }
        return node;
    }
};


int main(){
   Solution sol;
   TreeNode *root = new TreeNode(6); 
   TreeNode *l1 = new TreeNode(2); 
   TreeNode *l2 = new TreeNode(8); 
   TreeNode *l3 = new TreeNode(0); 
   TreeNode *l4 = new TreeNode(4); 
   TreeNode *l5 = new TreeNode(7); 
   TreeNode *l6 = new TreeNode(9); 
   TreeNode *l7 = new TreeNode(3); 
   TreeNode *l8 = new TreeNode(5); 
   root->left = l1;
   root->right = l2;
   l1->left=l3;
   l1->right=l4;
   l2->left=l5;
   l2->right=l6;
   l4->left=l7;
   l4->right=l8;
   auto node = sol.lowestCommonAncestor(root, l7, l8);
   cout << node->val << "\n";
   node = sol.lowestCommonAncestor(root, l7, l3);
   cout << node->val << "\n";
   node = sol.lowestCommonAncestor(root, l3, l6);
   cout << node->val << "\n";

}