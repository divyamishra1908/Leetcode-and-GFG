// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends
class Solution{
long fac(int x){
       long ans=1;
       for(int i=1;i<=x;i++){
           ans=ans*i;
       }
       return ans;
   }
public:
   long posIntSol(string s)
   {
       int r=0,i=0;
          while(s[i]!='='){
           if(s[i]!='+' && s[i]!='='){
               r++;
           }
           i++;
       }
       long den=fac(r-1);
       string N=s.substr(i+1,s.size()+1);
      int n=stoi(N);
      if(n==1){return 0;}
       long num=1;
       while(r>1){
           n=n-1;
           num=num*n;
           r--;
       }
       return num/den;
   }

};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.posIntSol(s)<<endl;
    }
    return 0;
}
  // } Driver Code Ends