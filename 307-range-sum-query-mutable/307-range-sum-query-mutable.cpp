class NumArray {
    int n = 0;
    vector<int> a;    
    void _create(int idx,vector<int> &nums,int l,int r){
        if(l > r) return;
        else if(l == r) a[idx] = nums[l];
        else{
            int mid = (l+r)/2;
            _create(2*idx + 1,nums,l,mid);
            _create(2*idx + 2,nums,mid+1,r);
            a[idx] = a[2*idx+1] + a[2*idx+2];
        }
    }
    void _update(int data,int i,int idx,int l,int r){
        if(i < l || i > r) return;
        if(l == r) a[idx] = data;
        else{
            int mid = (l+r)/2;
            _update(data,i,2*idx+1,l,mid);
            _update(data,i,2*idx+2,mid+1,r);
            a[idx] = a[2*idx+1] + a[2*idx+2];
        }
    }
    int findSum(int idx,int l,int r,int s,int e){
        if(e < l || r < s) return 0;
        if(s <= l && r <= e) return a[idx];
        else{
            int mid = (l+r)/2;
            return findSum(2*idx+1,l,mid,s,e) + findSum(2*idx+2,mid+1,r,s,e);
        }
    }
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        a.resize(n*4);
        _create(0,nums,0,n-1);
    }
    
    void update(int index, int val) {
        _update(val,index,0,0,n-1);
    }
    
    int sumRange(int left, int right) {
        return findSum(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */