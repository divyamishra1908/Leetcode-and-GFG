class Solution {
  public:
   int maximumScore(vector<int>& nums, vector<int>& multipliers) {
 
    int m = multipliers.size();
    int n = nums.size();
    int dp[m][m+1];  
    for(int i=0;i<m;i++){
        for(int j=0;j<m+1;j++){
            dp[i][j]=INT_MIN;  // initialization
        }
    }
    
    dp[0][0]=  multipliers[0]*nums[n-1];
    dp[0][1]=  multipliers[0]*nums[1-1];
  
    for(int i=0;i<m-1;i++){
        for(int j=0;j<=i+1;j++){
             
            dp[i+1][j+1]= max(dp[i+1][j+1],multipliers[i+1]*nums[j]+dp[i][j]); 
            dp[i+1][j]= max(dp[i+1][j],multipliers[i+1]*nums[j+n-2-i]+dp[i][j]);    
        }
        
    }
    
    int maxVal=INT_MIN;
    
    for(int i=0;i<m+1;i++){
        maxVal=max(dp[m-1][i],maxVal);
    }
    return maxVal;    
 }
 };