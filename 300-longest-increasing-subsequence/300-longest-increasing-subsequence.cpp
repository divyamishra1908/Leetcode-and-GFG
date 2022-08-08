class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int n = nums.size(), sol = 1;
		int *mat = new int[n];
		mat[0] = 1;
		for(int i = 1; i < n; i ++) {
			mat[i] = 1;
			for(int j = 0; j < i; j ++) 
				if(nums[i] > nums[j] && mat[i] < mat[j] + 1) mat[i] = mat[j] + 1;
			sol = max(mat[i], sol);
		}
		return sol;
	}
};