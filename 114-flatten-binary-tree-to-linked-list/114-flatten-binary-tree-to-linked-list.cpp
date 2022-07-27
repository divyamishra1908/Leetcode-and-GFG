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
    TreeNode* solver(TreeNode* root)
{
    if(!root || (!root->left && !root->right))
        return root;
    
    root->left = solver(root->left);
    root->right = solver(root->right);
    
    TreeNode* temp = root->left;
    
    if(temp)
    {
        while(temp->right)
        temp = temp->right;
    
        temp->right = root->right;
        root->right = root->left;
        root->left = NULL;

    }            
    
    return root;
    
}
void flatten(TreeNode* root) {
    root = solver(root);
}
};