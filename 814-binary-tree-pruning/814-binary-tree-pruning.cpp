class Solution {
public:
    // the idea is to use DFS to traverse the tree
    // if the current subtree satisfies one of the following conditions
    // 1. root value is 1
    // 2. left sub tree contains 1 
    // 3. right sub tree contains 1
    // then we return `root`
    // otherwise, we return nullptr
    TreeNode* pruneTree(TreeNode* root) {
        // if root is nullptr, then return nullptr
        if (!root) return nullptr;
        // DFS on left sub tree
        root->left = pruneTree(root->left);
        // DFS on right sub tree
        root->right = pruneTree(root->right);
        // !root->left means the left sub tree doesn't contain 1
        // !root->right means the right sub tree doesn't contain 1
        // !root->val means the current node value is 0
        // for this case, return nullptr
        // else we can keep the node
        return (!root->left && !root->right && !root->val) ? nullptr : root;
    }
};