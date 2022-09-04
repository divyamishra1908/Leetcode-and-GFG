class Solution {
public:
void solve(vector<pair<int,pair<int,int>>>&ans,TreeNode*root,int order,int level,int& mn,int& mx){
ans.push_back({level,{root->val,order}});
if(order<=mn) mn=order;
if(order>=mx) mx=order;

    if(!root->left and !root->right) return;
    
    if(root->left){
        solve(ans,root->left,order-1,level+1,mn,mx);
    }
    

    if(root->right){
        solve(ans,root->right,order+1,level+1,mn,mx);
    }
}


vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<pair<int,pair<int,int>>>ans;
    int order=0;
    int mi=INT_MAX;
    int mx=INT_MIN;
    
    solve(ans,root,order,0,mi,mx);
    vector<vector<int>> ans1;
    vector<int> temp;
    

    sort(ans.begin(),ans.end());

    for(int i=mi;i<=mx;i++){
        for(auto j: ans){
            if(j.second.second==i){
                temp.push_back(j.second.first);
            }
        }
        ans1.push_back(temp);
        temp.clear();
    }
    
    return ans1;
    
}
};