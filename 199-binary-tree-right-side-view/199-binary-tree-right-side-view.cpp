class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;q.push(root);
            
        while(!q.empty())
        {
            int n = q.size();
            for(int i = 0; i < n; i++){
                TreeNode* node = q.front();
                q.pop();
                if(i == 0) ans.push_back(node->val);
                if(node->right) q.push(node->right);
                if(node->left) q.push(node->left);
            }
        }
        return ans;
    }
};