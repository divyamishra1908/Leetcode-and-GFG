class Solution {
public:
    TreeNode* A(vector<int>& nums,int l,int r) {
        if(l>r)return NULL;
        int mid=(r+l)/2;
        TreeNode*root=new TreeNode(nums[mid],A(nums,l,mid-1),A(nums,mid+1,r));
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return A(nums,0,nums.size()-1);
    }
};