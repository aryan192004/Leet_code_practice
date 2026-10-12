/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
bool check(TreeNode* root, int k,unordered_set<int>& seen){
    if(root == NULL){
        return false;
    }
    int complement = k - root-> val;
    if(seen.count(complement)){
        return true;
    }
    seen.insert(root->val);
    return check(root->left,k,seen)||check(root->right,k,seen);
}
    bool findTarget(TreeNode* root, int k) {
      unordered_set<int>seen;
      return check(root,k,seen);  
    }
};