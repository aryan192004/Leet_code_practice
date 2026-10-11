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
bool bst= true;
vector<int>check;
int i=0;
void inorder(TreeNode* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    if (!check.empty() && root->val <= check.back()) {
            bst = false;
            return;
        }
    check.push_back(root->val);

    inorder(root->right);


}
    bool isValidBST(TreeNode* root) {
        inorder(root);
        return bst;
    }
};