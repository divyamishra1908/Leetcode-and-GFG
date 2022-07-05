class Solution {
public:
    //idea
    //finding wheather it is a starting element of the sequence or not
    int longestConsecutive(vector<int>& nums) {
        int count=0;
        // i am Using set because of O(1) time look up and insertion
        unordered_set<int>s;
        for(auto it:nums)
            s.insert(it);
        
        //here i am traversing the array 
//this will take at most O(n) time
        for(auto num:nums){
            if(s.find(num-1)==s.end())
            {
                int cnt=0;
                int element=num;
                while(s.find(element)!=s.end()){
                    cnt++;
                    element++;
                }
                count=max(count,cnt);
            }
        }
        return count;
    }
};