class Solution {
public:
    bool isPalindrome(int x) {
        long long int n,s=0,p;
        n=x;
        if(x<0)
            return false;
        else
            while(n!=0)
             {
                p=n%10;
                s=s*10+p;
                n=n/10;
            }
            if(s==x)
                return true;
            else
                return false;               
        
        }
};