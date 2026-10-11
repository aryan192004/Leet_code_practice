
class Solution {
public:
    void insert(TreeNode* root, TreeNode* node) {
        if (node->val < root->val) {
            if (root->left == NULL) {
                root->left = node;
                return;
            }
            insert(root->left, node);
        }
        else {
            if (root->right == NULL) {
                root->right = node;
                return;
            }
            insert(root->right, node);
        }
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = new TreeNode(val);

        if (root == NULL) {
            return node;
        }

        insert(root, node);
        return root;
    }
};
